<?php
// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'wordpress');

/** MySQL database username */
define('DB_USER', 'wordpressuser');

/** MySQL database password */
define('DB_PASSWORD', 'root');

/** MySQL hostname */
define('DB_HOST', 'localhost');

/** Database Charset to use in creating database tables. */
define('DB_CHARSET', 'utf8');

/** The Database Collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

define('AUTH_KEY',         'MJgvQ-B8[!H,Ar3YR/+Q|s:[LA2O@uWq =9y^4TRO+ytb-c}fQ=L($l]7eS6J+JO');
define('SECURE_AUTH_KEY',  'IvSAtEbWe-ka3.+NR~HPJ!2]8K@pT-A-;gTDtU*|1Ivg Y>Ehyz@#1-C-a2OxsZ,');
define('LOGGED_IN_KEY',    ')H5AXQw*8-K8+~i.=g)!{@WI8!QIfDnI;0bx2R2-yJRfut[]b))LH`pwEZv<T;s{');
define('NONCE_KEY',        'cD_.oy)p?_I+uk_K&Ph%( 0R2.*VP!?a=}%z+wC*Z*;XM3J.hLf?g4Xq|${)/<)R');
define('AUTH_SALT',        'vPIl/v-R!`3w8<|1z9KvIs{|9+xN(jfZU+URk;,IbFN5Hdt#gXlP|256is8H^f&O');
define('SECURE_AUTH_SALT', '*>&uS^EU}T2=G.i6_/> QjPiM|H!-n1r4SxH#?BPw7xWc`R*t`q%TaWB+3,=N]//');
define('LOGGED_IN_SALT',   '!=V3yuQ8kV.5:@?MC .-8Vqy;hx(k^85 Tz+u_4Z1Km+ah^~_z8$`a-LGztuiv %');
define('NONCE_SALT',       '0<v-[IGf1A9z&[c>u(m:bPy58URg+D6W0gFFi$ik{fW!k>N|-(2L?*.,5a76jNp&');

$table_prefix  = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
