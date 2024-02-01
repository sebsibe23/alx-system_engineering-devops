#!/usr/bin/env bash
# Check if nginx is running
if ! pgrep nginx > /dev/null
then
    # Start nginx
    service nginx start
fi

# Check if nginx is listening on port 80
if ! netstat -tuln | grep :80 > /dev/null
then
    # Modify nginx configuration to listen on port 80 and restart
    sed -i 's/listen  .*/listen 80;/' /etc/nginx/sites-available/default
    service nginx restart
fi
