#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##################################
# University of Wisconsin-Madison
# Author: Yaqi Zhang
##################################
# This module contains functions
# which can extract metadata of
# LeetCode algorithm problems
##################################

# standard library
import collections
import json
import re
import string
import time

# 3rd party library
import requests

# local library
from add_url import url_exist

def gen_url(problem_title):
    """Generate LeetCode url of the problem."""
    url_template = "https://leetcode.com/problems/{}"
    url = url_template.format(re.sub(r'[^\w\s]', '', problem_title))
    assert('`' not in url)
    return '-'.join(url.split()).lower()


def get_problems_info():
    """Extract information of leetcode algorithm problems, return dictionay."""
    url = "https://leetcode.com/api/problems/algorithms/"
    client = requests.session()
    response = client.get(url)
    response.raise_for_status()
    infos = response.json()
    infos = infos['stat_status_pairs']
    problems = collections.defaultdict(dict)
    for record in infos:
        stat = record['stat']
        idx = stat['frontend_question_id']
        problems[idx]['title']           = stat['question__title']
        problems[idx]['total_acs']       = stat['total_acs']
        problems[idx]['total_submitted'] = stat['total_submitted']
        problems[idx]['paid_only']       = record['paid_only']
        if problems[idx]['total_acs'] != 0:
            problems[idx]['accept_rate'] = (problems[idx]['total_acs'] /
                                            problems[idx]['total_submitted'])
        else:
            problems[idx]['accept_rate'] = 1
        problems[idx]['difficulty']      = record['difficulty']['level']
        problems[idx]['url']             = gen_url(problems[idx]['title'])
    return problems


if __name__ == "__main__":
    problems = get_problems_info()
