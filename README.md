Teambox Sign On Server - tbxsosd
================================

This is the authentication component in the Teambox Collaboration platform. It is responsible from maintaining user accounts and authenticating user connecting to the collaboration server. Unless you really know what you are doing, this software is useless on its own so you should like into getting the Teambox Installer script if you want to try the Teambox system, which includes this component.

Configuration
=============

Configuration of tbxsosd lies in /opt/teambox/etc/tbxsosd after installing through the Teambox install script. Most of the configuration is better left untouched but I will list here the most important configuration files and configuration entries.




Other interest
==============

Encryption
----------

This software include *advanced* capabilities for encryption/decryption of email message. It was meant to be used as plug-in, in-premise email encryption solution for business. Most of those features are now unused in the current system. 

LDAP authentication
-------------------

This software also include a decent implementation of external authentication using Active Directory. This was meant to supplement the mail encryption features described above within the premise of a business. This code might still be operational but it is currently left in its untested state. It was originally tested with Active Directory on Windows Server 2003.
