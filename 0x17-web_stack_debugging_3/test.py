# Assuming you want to execute the given command using Python
import subprocess

command = "sed -i 's/phpp/php/g' /var/www/html/wp-settings.php"
path = '/bin'

try:
    subprocess.run(command, shell=True, check=True, executable=path)
    print("Command executed successfully.")
except subprocess.CalledProcessError as e:
    print(f"Error executing command: {e}")
