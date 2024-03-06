# strace
# Fix 500 error when a GET HTTP method is requested
# to Apache web server
# This manifest consists of a single resource 
# declaration named 'fixed-phpp'.
# The exec resource type is responsible for executing 
# commands on the target system. Within the resource declaration, 
# there are two parameters specified.
#  By applying this Puppet manifest,
# the sed command will be executed with the specified parameters.
# Consequently, any instances of 'phpp' within the 
# /var/www/html/wp-settings.php file will be replaced with 'php',
# potentially resolving the 500 error
# that occurs when a GET HTTP method is requested 
# to the Apache web server.

exec { 'fixed-phpp':
  command => "sed -i 's/phpp/php/g' /var/www/html/wp-settings.php",
  path    => '/usr/local/bin/:/bin/';
}
