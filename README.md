Teambox Sign On Server - tbxsosd
================================

This is the authentication component in the Teambox Collaboration platform. It is responsible from maintaining user accounts and authenticating user connecting to the collaboration server. Unless you really know what you are doing, this software is useless on its own so you should like into getting the Teambox Installer script if you want to try the Teambox system, which includes this component.

## Configuration

Configuration of tbxsosd lies in /opt/teambox/etc/tbxsosd after installing through the Teambox install script. Most of the configuration is better left untouched but I will list here the most important configuration files and configuration entries.

### `client.conf`

### `db.conf`

`db.name`, `db.username`, `db.password`, `db.host`, `db.port`, `db.admin_username`, `db.admin_password`

Those configuration entries are for configuring access to PostgreSQL and I think they are self-explanatory. The `admin_username` and `admin_password` were meant to limit access to the main database user but to keep things simple this should be the same as `username` and `password`.

### `filter.conf`

Was used exclusively for mail encryption.

### `keysign.conf`

Was used exclusively for mail encryption.

### `ldap.conf`

Configuration for LDAP authentication. This is still enabled in the daemon and could theorically still be used to authenticate user on a collaboration server. I cannot provide documentation for this has this code has not been tested since the newest release.

### `log.conf`

Configuration for logging. Most is self explanatory and should not need to be modified.

### `otut.conf`

Was used exclusively for mail encryption.

### `pod.conf`

Was used exclusively for mail encryption for configuring "proof of delivery" (PoD) emails sent by the server.

### `server.conf`

This is where the most commonly modified options reside. Options in that file that sounds like they related to dealing with email were probably indeed meant to be only for email and thus won't have much relevance to this server when used only in the context of the collaboration server.

#### `server.user`

The system user that the server will switch to on start. This has been created for you.

#### `server.group`

Same as `server.user` but for the system group.

#### `server.listen_on`

The interface and port on which the server will listen through normal TCP. The collaboration daemon (KCD) (see the `kas` project) will actually connect to the tbxsosd so this address should probably be set to 127.0.0.1 but this needs further test.

#### `server.ssl_listen_on`

The interface and port on which the server will listen on by SSL. No longer necessary as the collaboration daemon directly connects to this server locally.

#### `server.log_verbosity`

The server verbosity is configured at the maximum of 9 since the release is of beta quality and having more logs could help you debug problems. You can lower this to a lower number if you think it's too verbose.

#### `server.pid_file`

The location of the PID file the server will save when it forks.

#### `server.data_file`

The server needs a small data file on the disk to operate. You can safely change this value if it doesn't match your system filesystem.

#### `server.password`

Despite being plainly set for a stupidly obvious value, this password is actually not used anymore!

#### `server.kas_address`

Address of the collaboration server. This should usually be the IP of the machine on which the server is installed.

#### `server.kas_port`

Port of the collaboration server. Should be 443 most of the time but could be changed to another value.

#### Preforked server control

Feel free to dabble with those value if you are the adventurous kind but don't blame me if your server magically disconnects people's request.

### `ssl.conf`

SSL isn't user anymore so you should leave this file alone.

### `tbxsosd.conf`

Master file which include all the other configuration files.

### `web.conf`

Empty configuration files. `web.conf` is the file that is loaded last and thus can be used to override any other configuration statement in the other files. You can add modified statement there or modify them in the relevant files if you don't care about preserving the default values.

## Other elements of interest

### Encryption

This software include *advanced* capabilities for encryption/decryption of email message. It was meant to be used as plug-in, in-premise email encryption solution for business. Most of those features are now unused in the current system. 

### LDAP authentication

This software also include a decent implementation of external authentication using Active Directory. This was meant to supplement the mail encryption features described above within the premise of a business. This code might still be operational but it is currently left in its untested state. It was originally tested with Active Directory on Windows Server 2003.
