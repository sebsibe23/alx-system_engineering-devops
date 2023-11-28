#!/usr/bin/env ruby
# Parameters: ARGV[0] - a string passed as
# a command line argument
# Returns: None. Prints to stdout.
# Description: This script scans the input string
# for occurrences of the pattern "hb?t?n" and prints them.

puts ARGV[0].scan(/hb?t?n/).join
