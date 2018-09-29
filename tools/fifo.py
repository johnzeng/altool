#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os, sys

# 创建的目录
path1 = "fifo_in_from_tester"

os.mkfifo( path1, 0644 )

print "路径被创建"
