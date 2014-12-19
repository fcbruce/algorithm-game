#!/bin/bash
#
# Author : fcbruce <fcbruce8964@gmail.com>
#
# Time : Fri 19 Dec 2014 12:08:30 PM CST
#
#

find ./code -name '*.class' | xargs rm -f
find ./code ! -name '*.*' | xargs rm -f

