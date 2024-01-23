#!/usr/bin/env bash
# using puppet

file { 'ect/ssh/ssh_config':
	ensure => present,

content =>"

	#ssh client configuration
	host*
	IdentityFile ~/.ssh/school
	PasswordAuthentication no
	",

}
