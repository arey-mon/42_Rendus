FROM debian:buster
MAINTAINER Apolline Reymond <apreymon@student.42.fr>

#INIT
RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y install nginx
RUN apt-get -y install wget
RUN apt-get -y install mariadb-server mariadb-client
RUN apt-get install -y vim

#PHP-SQL
RUN apt-get -y install php php-common
RUN apt-get -y install php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar -zxvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mkdir -p /var/www/wordpress/phpMyAdmin
RUN mv phpMyAdmin-4.9.0.1-all-languages /var/www/wordpress/phpMyAdmin
RUN rm phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN ln -s /usr/share/phpmyadmin /var/www/wordpress/phpmyadmin

#WORDPRESS
RUN wget https://fr.wordpress.org/latest-fr_FR.tar.gz
RUN tar -zxvf latest-fr_FR.tar.gz
RUN mkdir -p /var/www/wordpress
RUN mv wordpress /var/www/wordpress
RUN rm latest-fr_FR.tar.gz
RUN chown -R root:www-data /var/www/ #html/wordpress/
RUN chmod -R 755 /var/www/ #html/wordpress/
COPY /srcs/wordpress /etc/nginx/sites-available/
RUN ln -s /etc/nginx/sites-available/wordpress /etc/nginx/sites-enabled/

#SSL
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj '/C=FR/ST=75017/L=Paris/O=42/CN=wordpress'

RUN rm /var/www/wordpress/wordpress/wp-config-sample.php
COPY /srcs/config.inc.php /var/www/wordpress/phpmyadmin
COPY /srcs/wp-config.php /var/www/wordpress/wordpress/wp-config.php

COPY srcs/start.sh ./
CMD bash start.sh
