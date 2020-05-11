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
RUN apt-get -y update && apt-get -y install wget
RUN apt-get install -y php php-fpm php-gd php-mysql php-cli php-curl php-json
RUN wget https://fr.wordpress.org/latest-fr_FR.tar.gz
RUN tar -zxvf latest-fr_FR.tar.gz
RUN mkdir -p /var/www/html/wordpress
RUN mv wordpress /var/www/html
RUN apt-get install -y nginx
RUN apt-get install -y vim
#RUN ls /var/www/html/wordpress
#RUN ls /var/www/html

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
#EXPOSE 80
#CMD bash srcs/start.sh && tail -f /dev/null
#COPY . .
