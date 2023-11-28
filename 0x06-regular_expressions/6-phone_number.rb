#!/usr/bin/env ruby
# Parameters: ARGV[0] - The first command line argument
# Return: None
# Description: This script takes an argument from
# a command line and prints it if it's a 10-digit number.

puts ARGV[0].scan(/^\d{10,10}$/).join
