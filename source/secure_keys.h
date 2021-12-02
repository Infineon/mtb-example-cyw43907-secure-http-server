/******************************************************************************
* File Name: secure_keys.h
*
* Description: This file contains configuration parameters for the secure HTTP
* server and the server security keys such as server certificate, private key,
* and the root CA (certificate authority) to trust the client.
*
* Related Document: See README.md
*******************************************************************************
* $ Copyright 2021 Cypress Semiconductor $
*******************************************************************************/

/*******************************************************************************
* Include guard
*******************************************************************************/
#ifndef SECURE_KEYS_H_
#define SECURE_KEYS_H_

/* HTTPS server certificate. Copy from the HTTPS server certificate
 * generated by OpenSSL (See Readme.md on how to generate a SSL certificate).
 */
#define keySERVER_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIID5DCCAsygAwIBAgIUTpEusc2tDKwE4U+9er4knSrRQxAwDQYJKoZIhvcNAQEL\n"\
"BQAwezELMAkGA1UEBhMCSU4xEjAQBgNVBAgMCUthcm5hdGFrYTESMBAGA1UEBwwJ\n"\
"QmVuZ2FsdXJ1MQswCQYDVQQKDAJDWTEUMBIGA1UECwwLRW5naW5lZXJpbmcxITAf\n"\
"BgNVBAMMGG15c2VjdXJlaHR0cHNlcnZlci5sb2NhbDAeFw0yMTA0MTYxMDA5Mjla\n"\
"Fw0zMTA0MTQxMDA5MjlaMHsxCzAJBgNVBAYTAklOMRIwEAYDVQQIDAlLYXJuYXRh\n"\
"a2ExEjAQBgNVBAcMCUJlbmdhbHVydTELMAkGA1UECgwCQ1kxFDASBgNVBAsMC0Vu\n"\
"Z2luZWVyaW5nMSEwHwYDVQQDDBhteXNlY3VyZWh0dHBzZXJ2ZXIubG9jYWwwggEi\n"\
"MA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDllq/ckLwwveosi4dO+YLvBCyi\n"\
"fG4ZkSfx2rwaIW8sHC9xpbVcGRTk8ULKMQsX8kPTd22m4Lt4jOeP2y6+94GFljsT\n"\
"Ug6Z1mtc08f5h30HMTVZLTRCwQuIX9fm5UnXnwrsbXP4lHvtnxz3BzEzRxDl1kIW\n"\
"+QEfjGLrvgtLinhb1t7rGgDlMYLQuYJBVXxtaI2pLRCKlod1c+hKgpSSRZ8vGE9/\n"\
"7BOKWaL2NPfYalj5r+Wr1y6LUclfw6p1RjUj68HQtZczqCHucdlrRMqYGgl+CQBT\n"\
"P9kuCgzk6VBNPpqtuKZ378JiwbVpOzYaZALnTVxF1KlLnZk89/7RpC5kxrlPAgMB\n"\
"AAGjYDBeMB8GA1UdIwQYMBaAFLyRCI4LFmUBU0lCcXVWxQbLN+QlMAkGA1UdEwQC\n"\
"MAAwCwYDVR0PBAQDAgTwMCMGA1UdEQQcMBqCGG15c2VjdXJlaHR0cHNlcnZlci5s\n"\
"b2NhbDANBgkqhkiG9w0BAQsFAAOCAQEAiVIEkzPXg8B3g8UI0q3rDwsF1TlHIgR7\n"\
"E/EWxRuSsC0UQMRNL2z4hcDYBWEbxwOR7k3D/0CNS5fBe0cI3RrCWFriXSQJQoa/\n"\
"wiguy4U2hS8Sniy0naYH5MQpGzeYkD9CIvYPgrRM27gb/KWDO3GNA+lmxss2U8gQ\n"\
"DC53kNVx7MUQ2E/iN5kuRWXvdLDm7hCHXQRFSV/ZAYhso9pWEqz5tQSMT9IcNFU+\n"\
"eekbasKFI45R5igsyF1jXM9c3Opjs3pK99Ly7gv7Jf7taE2r5ZrcMOVKX2KGmRZs\n"\
"c8iFC0PNR12qQAqleX3wfMklVUVFmYfSQ8kqrYzXNaIFBwpJY/cmAQ==\n"\
"-----END CERTIFICATE-----"

/* Private key of the HTTPS server. Copy from the HTTPS server key
 * generated by OpenSSL (See Readme.md on how to create a private key).
 */
#define keySERVER_PRIVATE_KEY_PEM \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEpgIBAAKCAQEA5Zav3JC8ML3qLIuHTvmC7wQsonxuGZEn8dq8GiFvLBwvcaW1\n"\
"XBkU5PFCyjELF/JD03dtpuC7eIznj9suvveBhZY7E1IOmdZrXNPH+Yd9BzE1WS00\n"\
"QsELiF/X5uVJ158K7G1z+JR77Z8c9wcxM0cQ5dZCFvkBH4xi674LS4p4W9be6xoA\n"\
"5TGC0LmCQVV8bWiNqS0QipaHdXPoSoKUkkWfLxhPf+wTilmi9jT32GpY+a/lq9cu\n"\
"i1HJX8OqdUY1I+vB0LWXM6gh7nHZa0TKmBoJfgkAUz/ZLgoM5OlQTT6arbimd+/C\n"\
"YsG1aTs2GmQC501cRdSpS52ZPPf+0aQuZMa5TwIDAQABAoIBAQDI4xD97aa8/2/n\n"\
"ii7a63elrAFiK34q4NgSx1HPi3G7Ju5cgqIt88RUjsXiJQeP7GtsnRNU8U8YLDJx\n"\
"rVc5wVeTi+AlB6e+8979WlGgBO1hXa1QWj1gK4nryfEgF4CFKqRkO2E+IK5PPOob\n"\
"PC/Qrl4avV8WuspA0JW9sIwxjPfDYpbwtnVfWS3bvoM3imakXWwas5k+J7q+dqDJ\n"\
"32p9fzFaxK2vuiysjt+oses5R8I4N+kTI5NSzGBALwOOqX76RhkxFHCRrsVAuujx\n"\
"cZVXSN+gbN9Xc79Rdiev6AgvcrP5+7QqegPdJsP82KMK0m3PGIjcP46PD0+uLKFG\n"\
"xZZX0AABAoGBAP4Usg3luuq/r7C5CLu04TTXSFWxaDm6znwfbmL2ojIATjT/UT8H\n"\
"YCcBqbo7SXK6g5qrBmRREjUywHSbPEwBXtgUkxEzGKW+wMmYCFHcwCXjsocrAeKv\n"\
"hVytLtBEDK9HUs243iJ3EJwJeWafKkRTrwXH2rV1IDEJAwuYpyuSs0lrAoGBAOdS\n"\
"ocd4062LaWUBYcLMOY8kCaQOCJ78tiPhXRpWBhMRHqMgJCHEbElr5N205qI/MwBh\n"\
"5udp0jVDOuhu+v4ePfgPXBZnRxjU1XJ7+ZWMpRKPtecjTLfmR5N58a2lN8LqL1rc\n"\
"k7QaW87t6j1Ss33bBM1mOXnFyPvtsAYi0JhnVVStAoGBAIdUyJ3kXhHJNbAgbklk\n"\
"h4uYm1uhWc1d9bthFm+5xBxz0zQhRcoXiJxeI2QhTfbA53YLYCUwlU0mkiHJyW0G\n"\
"Udkv5EGGALvPhWobA1tvBB1qUV3zh1aRfKwnRkcB5+u4Rp9yt0aOOpeR6ErDvkSU\n"\
"eiXPFGwQTawwi6Gyll/8DGivAoGBALF3pKQrH4LqDN6v07emBJa7mCXjmluXF4mp\n"\
"cUsuKhTgsneFxhKd5lHh08D/810QTWmCsqphdiLkxEHkOu1QeExiREzvyQzU5Dij\n"\
"wlQohdAarvx4CXig09Lh4DdPJNuF3PTBexPWkQ7NWkLXutrYd/O49GlnAw28Sao7\n"\
"dXsm88E1AoGBAOVd0nGxP3RaEUUXTCPMfPkjZO/3WqZP1rulVxnSJt6zNMVLFhc2\n"\
"fFAqxuVzbT682d/snKbI9OKBKY4/xSAUSjJfv2ox7+dCLW0qM/fYFHmQzX5qWtwm\n"\
"tw0WC6auyxNiSyWyDHgZj8Vp1g5DuJwEt8nVbk4Oe+YUeYcY0rcy8GDC\n"\
"-----END RSA PRIVATE KEY-----"

/* HTTPS client certificate. In this example this is the RootCA
 * certificate so as to verify the HTTPS client's identity. */
#define keyCLIENT_ROOTCA_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIID1zCCAr+gAwIBAgIUaoSKMNMkYdiTur8umVv9y3MjnHIwDQYJKoZIhvcNAQEL\n"\
"BQAwezELMAkGA1UEBhMCSU4xEjAQBgNVBAgMCUthcm5hdGFrYTESMBAGA1UEBwwJ\n"\
"QmVuZ2FsdXJ1MQswCQYDVQQKDAJDWTEUMBIGA1UECwwLRW5naW5lZXJpbmcxITAf\n"\
"BgNVBAMMGG15c2VjdXJlaHR0cHNlcnZlci5sb2NhbDAeFw0yMTA0MTYxMDA5Mjla\n"\
"Fw0zMTA0MTQxMDA5MjlaMHsxCzAJBgNVBAYTAklOMRIwEAYDVQQIDAlLYXJuYXRh\n"\
"a2ExEjAQBgNVBAcMCUJlbmdhbHVydTELMAkGA1UECgwCQ1kxFDASBgNVBAsMC0Vu\n"\
"Z2luZWVyaW5nMSEwHwYDVQQDDBhteXNlY3VyZWh0dHBzZXJ2ZXIubG9jYWwwggEi\n"\
"MA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDPhRi2QhLYUAm8/n+iHzMOD9wU\n"\
"iU/nvIrGxIaAZRN5RUfQKIRzam6d8cGAegRYMqAii7m4RDc87XINNKhZDWIbXzJ7\n"\
"SRkeTDQRB5LRNZu5xkYlJVK480TaRlshwFT1oBJ1j1eMhaKADuAWoRyRCsj5u5a0\n"\
"F87shJm6XoI+ZfmFdOh9OzIqPBC2vODxf2J/cbFemdMCqnb7BguwJ3RLvFu0/W2P\n"\
"K4l/IgaSYFnBhUhRN2AgVuArTYeH80EChNHJ5hfCKIX1t3ZRHGUMzPW7fyzaCRJK\n"\
"Tt4X7wHtThTGYyIbHrpIpJU3aIGLnFUcsf2YAlHL9clhOO+/5tp84QAz3GcXAgMB\n"\
"AAGjUzBRMB0GA1UdDgQWBBS8kQiOCxZlAVNJQnF1VsUGyzfkJTAfBgNVHSMEGDAW\n"\
"gBS8kQiOCxZlAVNJQnF1VsUGyzfkJTAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3\n"\
"DQEBCwUAA4IBAQCe9mlauXDWnqbNxvi5X6rMqv4lGrcStHQgcjT79oOt9gXrCQcx\n"\
"fz7f3opABB/nlvF/Puaf9qnVFyM/z3MH4kAciDCijVqGivchvcHUbICU+I0PJ5QB\n"\
"3s4xL1Xg6zjaWf8MRzScEOD98T38GfC9t01A4N1YAlo1Dp/w/5tRc5otAgObvH0c\n"\
"q/DF4JXmhGudnXyFlgBjPol7oZ+A79FBTehPNAoDpkgPUoMKazDLbDwVe+Riiqlq\n"\
"eSFXDRWtNaE0zdVI9jjiX68RqBR7lrtSR7vdCWKJa0WxMnnF+jTEZFr4+jjw4qlP\n"\
"cDao9N0IreSwA7MSg34hKue/CAXNbXgF9Tup\n"\
"-----END CERTIFICATE-----"

#endif /* SECURE_KEYS_H_ */

/* [] END OF FILE */
