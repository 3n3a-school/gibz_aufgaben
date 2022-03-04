FROM php:8.0-apache
RUN apt-get update && apt-get upgrade -y
RUN docker-php-ext-install mysqli && docker-php-ext-enable mysqli
RUN apt-get install -y libicu-dev
RUN docker-php-ext-configure intl && docker-php-ext-install intl && docker-php-ext-enable intl