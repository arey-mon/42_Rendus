FROM debian:buster
MAINTAINER Apolline Reymond <apreymon@student.42.fr>

#INIT
RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y install nginx
RUN apt-get -y install wget
RUN apt-get -y install mariadb-server mariadb-client
RUN apt-get install -y vim
RUN apt-get install -y openssl

#Installing PHP for Processing
RUN apt-get -y install php-fpm php-mysql

#WORDPRESS
RUN wget https://fr.wordpress.org/latest-fr_FR.tar.gz
RUN tar -zxvf latest-fr_FR.tar.gz
RUN mkdir -p /var/www/wordpress
RUN mv wordpress /var/www/wordpress
RUN rm latest-fr_FR.tar.gz
RUN chown -R root:www-data /var/www/
RUN chmod -R 755 /var/www/
COPY /srcs/wordpress /etc/nginx/sites-available/
RUN ln -s /etc/nginx/sites-available/wordpress /etc/nginx/sites-enabled/

#MARIADB
RUN mkdir /var/www/wordpress/mariadb
COPY srcs/create_tables.sql /var/www/wordpress/mariadb
RUN service mysql start &&\
    mariadb < /var/www/wordpress/mariadb/create_tables.sql && \
	mariadb -e "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" && \
    mariadb -e "GRANT ALL ON wordpress.* TO 'wordpressuser'@'localhost' IDENTIFIED BY 'root' WITH GRANT OPTION;" &&\
    mariadb -e "FLUSH PRIVILEGES;"

#SSL
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj '/C=FR/ST=75017/L=Paris/O=42/CN=wordpress'

#PHP-SQL
RUN apt-get -y install php php-common
RUN apt-get -y install php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline
RUN apt-get install -y php-json php-mbstring
RUN mkdir -p /var/www/wordpress/phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar -zxvf phpMyAdmin-4.9.0.1-all-languages.tar.gz --strip-components 1 -C /var/www/wordpress/phpmyadmin
RUN rm phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN ln -s /usr/share/phpmyadmin /var/www/wordpress/phpmyadmin

#RUN rm /var/www/html/index.html
RUN rm /var/www/wordpress/wordpress/wp-config-sample.php
COPY /srcs/config.inc.php /var/www/wordpress/phpmyadmin
COPY /srcs/wp-config.php /var/www/wordpress/wordpress/wp-config.php

COPY srcs/start.sh ./
CMD bash start.sh
