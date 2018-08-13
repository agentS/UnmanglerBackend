FROM ngrest

COPY . /usr/src/projects
RUN ngrest clean
RUN ngrest build
RUN cp .ngrest/local/build/services/unmangler.so /root/.ngrest/ngrest-build/deploy/share/ngrest/services

COPY apache2/unmangler.conf /etc/apache2/sites-available/000-default.conf

#ENTRYPOINT [ "/bin/bash" ]
ENTRYPOINT [ "/usr/sbin/apache2ctl", "-D", "FOREGROUND" ]
