## Running Perl programs

### On Ubuntu Linux (with Apache installed)

Place all the perl script files in the folder meant for CGI scripts as mentioned in the configuration file in `/etc/apache2/sites-available/default`. Mostly this will be /usr/lib/cgi-bin by default. Follow this [link](http://prometheansacrifice.wordpress.com/2013/12/07/running-perl-cgi-scripts/) for more details.

 Access them on the browser using `http://localhost/cgi-bin/filename.pl`

Make sure to give `x` access to the `.pl` files

    sudo chomd a+x filename.pl

Its convenient to login as root to execute these programs. In such cases, `sudo` i unnecessary.

### On Fedora Linux as prescribed by the VTU

Place the perl files in /var/www/cgi-bin. Access them on the browser using `http://localhost/cgi-bin/filename.pl`


## Running HTML and PHP

### On Ubuntu

HTML and PHP files can be placed in `/var/www` itself and can be accessed from the browser as `http://localhost/filename.php` or `http://localhost/filename.html`

### On Fedora

HTML and PHP files are placed in `/var/www/html`. Access them on the browser like Ubuntu.