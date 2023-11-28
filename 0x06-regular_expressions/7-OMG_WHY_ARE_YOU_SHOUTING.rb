#!/usr/bin/env ruby
# Parameters: ARGV[0] - The first command line argument
# Return: None
# Description: This script takes an argument from
# a command line and prints all the uppercase letters in it.

puts ARGV[0].scan(/[A-Z]*/).join
