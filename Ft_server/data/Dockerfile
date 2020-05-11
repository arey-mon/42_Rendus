#EXPLANATIONS
# Copy the file from your host to your current location.
# Run the command inside your image filesystem.
# Inform Docker that the container is listening on the specified port at runtime.
# Run the specified command within the container.
# Copy the rest of your app's source code from your host to your image filesystem.
#MORE https://docs.docker.com/get-started/part2/
FROM debian:buster
MAINTAINER Apolline Reymond <apreymon@student.42.fr>
#WORKDIR /Users/apollinereymond/GIT/ft_server/data
#COPY srcs/start.sh /Users/apollinereymond/GIT/Ft_server/data/srcs

#INIT
RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y install wget
#RUN apt-get install systemd #could be useful for systemcld command. To check again
RUN apt-get -y install mariadb-server mariadb-client
RUN apt-get install -y vim
#RUN rm var/www/html/index.nginx-debian.html

#PHP
RUN apt-get -y install php php-common
RUN apt-get -y install php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline
#php-cli php-fpm php-json php-pdo php-mysql php-zip php-gd  php-mbstring php-curl php-xml php-pear php-bcmath
#RUN apt-get install -y php php-fpm php-gd php-mysql php-cli php-curl php-jsoni
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar -zxvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mkdir -p /var/www/html/phpMyAdmin
RUN mv phpMyAdmin-4.9.0.1-all-languages /var/www/html/phpMyAdmin
RUN rm phpMyAdmin-4.9.0.1-all-languages.tar.gz

#WORDPRESS
RUN wget https://fr.wordpress.org/latest-fr_FR.tar.gz
RUN tar -zxvf latest-fr_FR.tar.gz
RUN mkdir -p /var/www/html/wordpress
RUN mv wordpress /var/www/html
RUN rm latest-fr_FR.tar.gz
RUN chown -R www-data:www-data /var/www/html/wordpress/
RUN chmod -R 755 /var/www/html/wordpress/
#RUN rm /var/www/html/wordpress/wp-config-sample.php #needs to be done with ADD link and new config.php file set
#RUN ls /var/www/html/wordpress
#RUN ls /var/www/html

#NGINX
RUN apt-get install -y nginx
#RUN apt-get install -y unit-php #installed from exec

WORKDIR /var
RUN echo "service php7.3-fpm start" > stuck.sh
RUN echo "service nginx start" >> stuck.sh
RUN echo "service mysql start" >> stuck.sh
RUN echo "while true;" >> stuck.sh
RUN echo "	do sleep 10000;" >> stuck.sh
RUN echo "done" >> stuck.sh
CMD bash /var/stuck.sh

#ADD ./srcs/wordpress ./etc/nginx/sites-available/wordpress
#ADD ./srcs/wp-config.php ./var/www/html/wordpress/wp-config.php
#COPY srcs/start.sh ./
#CMD bash start.sh #&& tail -f /dev/null
#COPY . .
