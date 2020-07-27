#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##################################
# University of Wisconsin-Madison
# Author: Yaqi Zhang
##################################
# This module can pick some LeetCode
# problems.
##################################

# standard library
import argparse
import random
import re
import sys

# local library
from lc_crawler import get_problems_info, gen_url


def random_pick(n, lang, difficulty, todo, choice):
    """Pick n questions of a specific language with specific difficulty."""

    readme_path_dict = {'python': '../python3.md',
                        'c++'    : '../cpp.md',
                        'java'   : '../java.md',
                       }

    diff_dict = {1 : "EASY", 2 : "MEDIUM", 3 : "HARD"}

    # collect finished problem indexes
    readme_path = readme_path_dict[lang]
    with open(readme_path, 'r') as in_f:
        text = in_f.read()
        done_list = [item.group()[1:-1]
                    for item in re.finditer(r'\|\d+\|', text)]
        done_set = {int(x) for x in done_list}
    print("Finished {} problems in {}.".format(len(done_set), lang.capitalize()))

    # featch algorithm problems indexes (problems is a dict: index --> dict)
    problems = get_problems_info()

    # remove finished problems when todo is True
    if todo:
        cands = problems.keys() - done_set
    else:
        cands = list(problems.keys())

    # filter problem difficulty
    cands = [idx for idx in cands
            if 'difficulty' in problems[idx] and
            problems[idx]['difficulty'] == difficulty]

    if choice == 'free':
        cands = [idx for idx in cands if not problems[idx]['paid_only']]
    elif choice == 'paid':
        cands = [idx for idx in cands if problems[idx]['paid_only']]

    # pick n problems randomly
    actual_n = min(n, len(cands))
    print("Pick {} {} problems out of {} problems.".format(actual_n, diff_dict[difficulty], len(cands)))
    picks = random.sample(cands, actual_n)
    for pick in picks:
        problem_title = problems[pick]['title']
        print("{}. {} {}".format(pick, problem_title, gen_url(problem_title)))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Pick Problems")
    parser.add_argument('-n', '--number', type=int, default=2, help='number of questions')
    parser.add_argument('-d', '--diff', type=int, default=2, choices=[1,2,3], help='Difficulty: easy(1), medium(2), hard(3)')
    parser.add_argument('-l', '--lang', type=str, default='c++',
            choices=['python', 'java', 'c++'], help='Programming language: python/java/c++')
    parser.add_argument('-t', '--todo', default=False, action='store_true', help='Set to only pick unfinished problems')
    parser.add_argument('-c', '--choice', type=str, default='all',
            choices=['all', 'free', 'paid'], help='Question choice: all/free/paid')
    args = parser.parse_args()
    num = args.number
    lang = args.lang
    difficulty = args.diff
    todo = args.todo
    choice = args.choice
    random_pick(num, lang, difficulty, todo, choice)
