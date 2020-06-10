#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##################################
# University of Wisconsin-Madison
# Author: Yaqi Zhang
##################################
# This module contains script that add
# url of leetcode problem
##################################

# standard library
import os
import sys
import time

# 3rd party library
import requests

SLEEP_TIME = 0.1

def problem_url_exist(problem, sleep_time=1.5):
    # problem format is "Two-Sum"
    prefix = "https://leetcode.com/problems/"
    url = prefix + problem.lower() + '/'
    time.sleep(sleep_time)
    return url_exist(url), url


def url_exist(url):
    headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36'}
    request = requests.get(url, headers=headers)
    return request.status_code == 200


def check_urls(base_dir):
    """check if urls are available."""
    cnt, nwrongs = 0, 0
    for fn in sorted(os.listdir(base_dir), reverse=True): # folder name
        if os.path.isdir(os.path.join(base_dir, fn)):
            num, rest = fn.split('-', 1)
            """
            num = int(num)
            if num not in checks:
                continue
            """
            cnt += 1
            time.sleep(SLEEP_TIME)
            exists, url = problem_url_exist(rest)
            if not exists:
                nwrongs += 1
                print("{}:{}".format(num, rest))
    print("There are {} wrong folder names".format(nwrongs))


def fix_folder_names(base_dir):
    """using Python3 question folder names as reference, fix question folder names of other languages (C++/Java)."""
    # read Python3 folder names to references
    references = {}
    reference_dir = "../Python3"
    for fn in sorted(os.listdir(reference_dir)):
        if os.path.isdir(os.path.join(reference_dir, fn)):
            num, rest = fn.split('-', 1)
            num = int(num)
            references[num] = fn
    renames = []
    for fn in sorted(os.listdir(base_dir), reverse=True):
        if os.path.isdir(os.path.join(base_dir, fn)):
            num, rest = fn.split('-', 1)
            num = int(num)
            ref_folder_name = references.get(num, None)
            if ref_folder_name is not None and ref_folder_name.lower() != fn.lower():
                renames.append((os.path.join(base_dir, fn), os.path.join(base_dir, ref_folder_name)))
    for src, target in renames:
        print(f"rename {src} to {target}")
        os.rename(src, target)



if __name__ == "__main__":
    ## 1. check whether urls are valid
    # base_dir = '../Python3'
    base_dir = '../C++'
    # check_urls(base_dir)

    ## 2. fix folder names based on Python3 folder names
    # base_dir = '../C++'
    # base_dir = '../Java'
    # fix_folder_names(base_dir)
