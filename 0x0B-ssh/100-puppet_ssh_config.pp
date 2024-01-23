#!/usr/bin/env bash
include stdlib
# using puppet

file { 'ect/ssh/ssh_cofig':
	ensure => present,

content =>"

	#ssh client configuration
	host*
	IdentityFile ~/.ssh/school
	PasswordAuthentication no
	",

}
