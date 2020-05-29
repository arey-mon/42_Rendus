
#EXPLANATIONS
# Copy the file from your host to your current location.
# Run the command inside your image filesystem.
# Inform Docker that the container is listening on the specified port at runtime.
# Run the specified command within the container.
# Copy the rest of your app's source code from your host to your image filesystem.
#MORE https://docs.docker.com/get-started/part2/
FROM debian:buster
MAINTAINER Apolline Reymond <apreymon@student.42.fr>

#COPY srcs/start.sh /Users/apollinereymond/GIT/Ft_server/data/srcs

RUN apt-get -y update && apt-get -y install wget
RUN apt-get install -y php php-fpm php-gd php-mysql php-cli php-curl php-json
RUN wget https://fr.wordpress.org/latest-fr_FR.tar.gz
RUN tar -zxvf latest-fr_FR.tar.gz
RUN mkdir -p /var/www/html/wordpress/
RUN mv wordpress /var/www/html/
RUN chown -R www-data:www-data /var/www/html/wordpress/
RUN chmod -R 755 /var/www/html/wordpress/
RUN rm latest-fr_FR.tar.gz
#RUN rm var/www/html/index.nginx-debian.html && rm /var/www/html/wordpress/wp-config-sample.php
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar -zxvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages /var/www/html/phpMyAdmin
RUN rm phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN ls /var/www/html/wordpress
#ADD ./srcs/wordpress ./etc/nginx/sites-available/wordpress
#ADD ./srcs/wp-config.php ./var/www/html/wordpress/wp-config.php
#EXPOSE 80
#CMD bash srcs/start.sh && tail -f /dev/null

#COPY . .
