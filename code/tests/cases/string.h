

MODULE(string, {

//////////////// zpl_char_to_lower

    IT("can transform ASCII characters to lower case", {
        char lowerCase[] = {'\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08', '\t', '\n',
                            '\x0b', '\x0c', '\r', '\x0e', '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14',
                            '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e',
                            '\x1f', ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
                            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
                            '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                            'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`',
                            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                            'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f', '\x80'};
        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++)
        {
            EQUALS(zpl_char_to_lower((char)i), lowerCase[i]);
        }
    });

//////////////// zpl_char_to_upper

    IT("can transform ASCII characters to upper case", {
        char upperCase[] = {'\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08', '\t', '\n',
                            '\x0b', '\x0c', '\r', '\x0e', '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15',
                            '\x16', '\x17', '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',
                            '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0',
                            '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@',
                            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                            'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`',
                            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                            'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '{', '|', '}', '~', '\x7f', '\x80'};
        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++)
        {
            EQUALS(zpl_char_to_upper((char)i), upperCase[i]);
        }
    });

//////////////// zpl_char_is_space

    IT("can check if ASCII characters are space characters", {
        zpl_b32 isSpace[] = {
            false, false, false, false, false, false, false, false,
            false, true, true, true, true, true, false, false, false,
            false, false, false, false, false, false, false, false, false, false,
            false, false, false, false, // seperator control characters not classes as space
            false, true, false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false};

        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++) {
            EQUALS(zpl_char_is_space((char)i), isSpace[i]);
        }
    });

//////////////// zpl_char_is_digit

    IT("can check if ASCII characters are decimal digits", {
        zpl_b32 isDigit[] = {
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false,
            false, false, false,
            true, true, true, true, true, true, true, true, true, true,
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false};

        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++) {
            EQUALS(zpl_char_is_digit((char)i), isDigit[i]);
        }
    });

//////////////// zpl_char_is_hex_digit

    IT("can check if ASCII characters are hexidecimal digits", {
        zpl_b32 isHexDigit[] = {
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, true,
            true, true, true, true, true, true, true, true,
            true, false, false, false, false, false, false,
            false, true, true, true, true, true, true, false,
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false,
            false, false, false, false, true, true, true, true,
            true, true, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, false,
            false, false, false, false};
        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++) {
            EQUALS(zpl_char_is_hex_digit((char)i), isHexDigit[i]);
        }
    });

//////////////// zpl_char_is_alpha

    IT("can check if ASCII characters are alphabet characters", {
        zpl_b32 isAlpha[] = {
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false, 
            false, false, false, false, false, false, false, 
            false, false, false, false, false, false, false, 
            false, false, false, false, false, false, false, 
            false, false, false, false, false, false, false, 
            false, false, false, false, false, false, false, 
            false, false, false, false, false, false, false, 
            false, false, true, true, true, true, true, true, 
            true, true, true, true, true, true, true, true, true,
            true, true, true, true, true, true, true, true, true, 
            true, true, false, false, false, false, false, false, 
            true, true, true, true, true, true, true, true, true,
            true, true, true, true, true, true, true, true, true, 
            true, true, true, true, true, true, true, true, false, 
            false, false, false, false, false};
        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++) {
            EQUALS(zpl_char_is_alpha((char)i), isAlpha[i]);
        }
    });

//////////////// zpl_char_is_alphanumeric

    IT("can check if ASCII characters are alphabet or decimal numeric characters", {
        zpl_b32 isAlphaNumeric[] = {
            false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false};
        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++) {
            EQUALS(zpl_char_is_alphanumeric((char)i), isAlphaNumeric[i]);
        }
    });

//////////////// zpl_digit_to_int

    IT("can convert ASCII decimal digit characters to integers", {
        zpl_i32 digits[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -49, -48, -47, -46, -45, -44, -43, -42, -41, -40, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++) {
            EQUALS(zpl_digit_to_int((char)i), digits[i]);
        }
    });

//////////////// zpl_hex_digit_to_int

    IT("can convert ASCII hexidecimal digit characters to i32 integers", {
        zpl_i32 hexDigits[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++) {
            EQUALS(zpl_hex_digit_to_int((char)i), hexDigits[i]);
        }
    });

//////////////// zpl_char_to_hex_digit

    IT("can convert ASCII hexidecimal digit characters to u8 integers", {
        zpl_u8 hexDigits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++) {
            EQUALS(zpl_char_to_hex_digit((char)i), hexDigits[i]);
        }
    });

//////////////// zpl_char_is_control

    IT("can check if ASCII characters control characters", {
        zpl_b32 isControl[] = { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false };
        size_t rangeStart = 0;
        size_t rangeEnd = 128;
        size_t i;

        for (i = rangeStart; i <= rangeEnd; i++) {
            EQUALS(zpl_char_is_control((char)i), isControl[i]);
        }
    });

//////////////// zpl_str_to_lower

    IT("can transform NULL string to lowercase", {
        zpl_str_to_lower(NULL);
    });

    IT("can transform string length=1 to lowercase", {
        char testString[] = "A";
        zpl_str_to_lower(testString);
        STREQUALS(testString, "a");
    });

    IT("can transform string length=1000 to lowercase", {
        char testString[] = "4yISTS2afHajVqlCW1i9myvtdXfjAVT1v7p7aNLRQE64iS6Uzd8V79WIebfDmeTKa598JZzebEvG2bS5dZWGVurnRUfXynzp9KUYF6H4TcAn4rgunMVqXgEABujB9zICeKWwVuy8u44MkBPIJohmvbJA1pX6UzfXwdnXcHRi0mq3c5CXVn2pRRZ5Q61qjplYPH02JWlHOqn1GffW8ZtNyambylm62oBqJAj5jneJoyTuyHp45q16Qpu71EXL6v0EzsGyie0WqQPIWZyhhw7Kby199DrYcAJWz5JpWYBoN2DLvrKJRPO7ml2l1FqH3bjxQ7oS8QVVML5JdSOzmsysGXXWhs97hcWcf6LDOgpgnwJrwBbX3f5toSiyR4vr6QT1434dWC81AQWobW16A2ZDpraulEKTz6Ad4ZFyXubi7TfUicogJiylMKXN69V2FsuwUfinOyAqiGC4gky7oIUfzyyLR95qIOycvnZOqlpBUXHa7KRORl1Gm9q8F2afcxWMncGrNCdQRuDgg0nsczgFDdkcNWqV1IVRVQW945fThHhjHQIXky48gojT8WF7GkXEYQiFeq0Lf1jkNEN2lOOUeTVPneQXyxMHpi0pY8YyfjjV5GYjFeqlu0pRfgCNeTP1sdwca7egKcYCIHTDnxptJjO3kbz5Fks04TiZoM4zbhbklcAmhqyRSLiboLFe7ZmaNLewO2mzoYfCkFBrgpwDYV2PfY75RE3VZ4MtUnAw0R2LlfAKXKMeOzObJ3CXTin5KuRHdOeMoLqtkFsDQvAFIgbzAT8r6dRvKzM9hm9dphT00V3KGOz9mQZVUsrfLUYUSc8uvbLeyIdO4yl6QAncXcfEZV86ydEqHJLJFXTBYRf2hX3tXCiB5GcHwaS5tmaF2bw5BnuDpRIWh0JEIjN1vj0UvBwYJ9E5vO1s2N0xMTaTe6XLubLFGHqedPmRXLgGivtWxE3wzAcKK8fpQidLYA8ipOTtnwVRtxI0rJk4";
        const char testStringLower[] = "4yists2afhajvqlcw1i9myvtdxfjavt1v7p7anlrqe64is6uzd8v79wiebfdmetka598jzzebevg2bs5dzwgvurnrufxynzp9kuyf6h4tcan4rgunmvqxgeabujb9zicekwwvuy8u44mkbpijohmvbja1px6uzfxwdnxchri0mq3c5cxvn2prrz5q61qjplyph02jwlhoqn1gffw8ztnyambylm62obqjaj5jnejoytuyhp45q16qpu71exl6v0ezsgyie0wqqpiwzyhhw7kby199drycajwz5jpwybon2dlvrkjrpo7ml2l1fqh3bjxq7os8qvvml5jdsozmsysgxxwhs97hcwcf6ldogpgnwjrwbbx3f5tosiyr4vr6qt1434dwc81aqwobw16a2zdpraulektz6ad4zfyxubi7tfuicogjiylmkxn69v2fsuwufinoyaqigc4gky7oiufzyylr95qioycvnzoqlpbuxha7krorl1gm9q8f2afcxwmncgrncdqrudgg0nsczgfddkcnwqv1ivrvqw945fthhhjhqixky48gojt8wf7gkxeyqifeq0lf1jknen2loouetvpneqxyxmhpi0py8yyfjjv5gyjfeqlu0prfgcnetp1sdwca7egkcycihtdnxptjjo3kbz5fks04tizom4zbhbklcamhqyrslibolfe7zmanlewo2mzoyfckfbrgpwdyv2pfy75re3vz4mtunaw0r2llfakxkmeozobj3cxtin5kurhdoemolqtkfsdqvafigbzat8r6drvkzm9hm9dpht00v3kgoz9mqzvusrfluyusc8uvbleyido4yl6qancxcfezv86ydeqhjljfxtbyrf2hx3txcib5gchwas5tmaf2bw5bnudpriwh0jeijn1vj0uvbwyj9e5vo1s2n0xmtate6xlublfghqedpmrxlggivtwxe3wzackk8fpqidlya8ipottnwvrtxi0rjk4";
        zpl_str_to_lower(testString);
        STREQUALS(testString, testStringLower);
    });

//////////////// zpl_str_to_lower

    IT("can transform NULL strings to uppercase", {
        zpl_str_to_lower(NULL);
    });

    IT("can transform strings of length=1 to uppercase", {
        char testString[] = "a";
        zpl_str_to_upper(testString);
        STREQUALS(testString, "A");
    });

    IT("can transform strings of length=1000 to uppercase", {
        char testString[] = "xgn2EwYshi2JVOBwTk6G1EtQ6DsLohfoXc0YwkWUt0NrydgnNKfGGvd4U1rJN8jAhSZYge3dJ2CTyTCKqHFYGEwWaOqwwZrhYq8GUNQTPq85ljRCbeFMofCefnYiDpbN40nCuXOjlhqbxOxSl4HKeJP84pEUc7zmSSK31cCPduYfYQc3Q4qcsSTzE1RE47rULWOxsKUi0FuDy9J85bOjdFsNE56Pf3gBmxbDkW8Sy4masNsM5kQkIXw6wFez6jVceqCjTl9dUe9hA4f3ML3h56IxVsyCUaKC1uTpUhy13XmlN2W6HU2n01fxyNalmEKphTBJx09leZE5r4lAabgRkF4qjVBml7RgUePaVc1RpmdVb5nyr3XqFKDg2ekFp8urQY7kuHtFSm3B933CDaEaaYXFBq37xyzqGXJQuJPF5cr6e2UGO6CY1Z4ythT7pdG1XygMDDFL8fRti6JUKF0XngxJS3HOroxYGeXTnKbUMJJ8JR7Pzfot40jbx3XBWwXqQUvuC3qetg1StuCFLd121KeBvZOLqPSKB8s4Z8wpiwxb1TxpLA9apMhXhvUrcC3xNJ5usL28hijDsRMQk31GvTkS77wiaKR0e2poLoZw6HvwDoflSnowFVo8W8dX0xKiq4eaLjbMv4nfuA0K2tfBhPiKLuM0ZtXl5ilQ2Fz0WpfK9GdPywqbXSVoRg4KQLqBktuifxn9fmdC6oi6EPSVKMybqQGMER4dljJnAZ1WGBW4ZWJaKVR3mqBRk3JbUq5dfJaEzQbfJyp6Ymc5Jcd4XM24IVJn8zrCb05zdMrlOnsv5KRD4QuxDrSnzve6VoQfdLlxh80wVc3lulfQXMJ5rqzB8NAOoqGIEEn2dFWhuzUTGtTgduwe9FDU4CpKTCPhW706PrXxNBaWBv5tCeTRNV6LOoGWx6O5onVXrI5v5nZUX0FAnUdj8gzuUGgWxx0Z01wuEAT5tdrPh0xsiEI2phE1ErdlHDhsyhLFOX0U";
        const char testStringUpper[] = "XGN2EWYSHI2JVOBWTK6G1ETQ6DSLOHFOXC0YWKWUT0NRYDGNNKFGGVD4U1RJN8JAHSZYGE3DJ2CTYTCKQHFYGEWWAOQWWZRHYQ8GUNQTPQ85LJRCBEFMOFCEFNYIDPBN40NCUXOJLHQBXOXSL4HKEJP84PEUC7ZMSSK31CCPDUYFYQC3Q4QCSSTZE1RE47RULWOXSKUI0FUDY9J85BOJDFSNE56PF3GBMXBDKW8SY4MASNSM5KQKIXW6WFEZ6JVCEQCJTL9DUE9HA4F3ML3H56IXVSYCUAKC1UTPUHY13XMLN2W6HU2N01FXYNALMEKPHTBJX09LEZE5R4LAABGRKF4QJVBML7RGUEPAVC1RPMDVB5NYR3XQFKDG2EKFP8URQY7KUHTFSM3B933CDAEAAYXFBQ37XYZQGXJQUJPF5CR6E2UGO6CY1Z4YTHT7PDG1XYGMDDFL8FRTI6JUKF0XNGXJS3HOROXYGEXTNKBUMJJ8JR7PZFOT40JBX3XBWWXQQUVUC3QETG1STUCFLD121KEBVZOLQPSKB8S4Z8WPIWXB1TXPLA9APMHXHVURCC3XNJ5USL28HIJDSRMQK31GVTKS77WIAKR0E2POLOZW6HVWDOFLSNOWFVO8W8DX0XKIQ4EALJBMV4NFUA0K2TFBHPIKLUM0ZTXL5ILQ2FZ0WPFK9GDPYWQBXSVORG4KQLQBKTUIFXN9FMDC6OI6EPSVKMYBQQGMER4DLJJNAZ1WGBW4ZWJAKVR3MQBRK3JBUQ5DFJAEZQBFJYP6YMC5JCD4XM24IVJN8ZRCB05ZDMRLONSV5KRD4QUXDRSNZVE6VOQFDLLXH80WVC3LULFQXMJ5RQZB8NAOOQGIEEN2DFWHUZUTGTTGDUWE9FDU4CPKTCPHW706PRXXNBAWBV5TCETRNV6LOOGWX6O5ONVXRI5V5NZUX0FANUDJ8GZUUGGWXX0Z01WUEAT5TDRPH0XSIEI2PHE1ERDLHDHSYHLFOX0U";
        zpl_str_to_upper(testString);
        STREQUALS(testString, testStringUpper);
    });

//////////////// zpl_str_trim

    IT("can trim NULL strings", {
        SKIP();
        STREQUALS(zpl_str_trim(NULL, true), NULL);
        STREQUALS(zpl_str_trim(NULL, false), NULL);
    });

    IT("can trim strings with no whitespace", {
        char testString[] = "nowhitespace";
    });

    IT("can trim strings starting with whitespace", {
        char testString[] = " \n       \tstartwhitespace";
        STREQUALS(zpl_str_trim(testString, false), testString + 10);
    });

    IT("can trim strings ending with whitespace", {
        char testString[] = "endwhitespace        \t\t";
        STREQUALS(zpl_str_trim(testString, false), testString);
    });

    IT("can trim strings starting with whitespace excluding newlines", {
        char testString[] = " \n        \tstartwhitespace";
        STREQUALS(zpl_str_trim(testString, true), testString + 1);
    });

    IT("can trim strings ending with whitespace excluding newlines", {
        char testString[] = "endwhitespace \n       \t\t";
        STREQUALS(zpl_str_trim(testString, true), testString);
    });

//////////////// zpl_str_skip
    
    IT("can skip NULL strings", {
        SKIP();
        STREQUALS(zpl_str_skip(NULL, 0), NULL);
    });

    IT("can skip strings that contain a specific character", {
        char testString[] = "skipme1dontskipme";
        STREQUALS(zpl_str_skip(testString, '1'), testString + 6);
    });

    IT("can skip strings starting that do not contain a specified character", {
        char testString[] = "skipmeskipme";
        STREQUALS(zpl_str_skip(testString, '1'), testString + 12);
    });

//////////////// zpl_str_skip_any
    IT("can skip any NULL characters", {
        SKIP();
        STREQUALS(zpl_str_skip_any(NULL, NULL), NULL);
    });
    IT("can skip any with no specified characters", {
        char testString[] = "skipme";
        STREQUALS(zpl_str_skip_any(testString, ""), testString + 6);
    });

    IT("can skip string with single specified character", {
        char testString[] = "skipme1234dontskipme";
        STREQUALS(zpl_str_skip_any(testString, "1"), testString + 6);
    });

    IT("can skip string with multi specified characters", {
        char testString[] = "skipme1234dontskipme";
        STREQUALS(zpl_str_skip_any(testString, "2431"), testString + 6);
    });

//////////////// zpl_str_skip_literal

    IT("skip characters until specified character is found unescaped", {
        char testString[] = "\\skipme\\s";
        char* testSubString = testString+1;

        const char* result = zpl_str_skip_literal(testSubString, 's');
        puts(result);
        STREQUALS(result, testSubString);
    });

//////////////// zpl_str_control_skip
    

//////////////// zpl_strlen
//////////////// zpl_strnlen
//////////////// zpl_strcmp

    IT("can calculate length of a NULL string", {
        EQUALS(zpl_strlen(NULL), 0);
    });

    IT("can calculate length of an empty string", {
        EQUALS(zpl_strlen(""), 0);
    });

    IT("can calculate length of an string length=1000", {
        char testString[] = "4yISTS2afHajVqlCW1i9myvtdXfjAVT1v7p7aNLRQE64iS6Uzd8V79WIebfDmeTKa598JZzebEvG2bS5dZWGVurnRUfXynzp9KUYF6H4TcAn4rgunMVqXgEABujB9zICeKWwVuy8u44MkBPIJohmvbJA1pX6UzfXwdnXcHRi0mq3c5CXVn2pRRZ5Q61qjplYPH02JWlHOqn1GffW8ZtNyambylm62oBqJAj5jneJoyTuyHp45q16Qpu71EXL6v0EzsGyie0WqQPIWZyhhw7Kby199DrYcAJWz5JpWYBoN2DLvrKJRPO7ml2l1FqH3bjxQ7oS8QVVML5JdSOzmsysGXXWhs97hcWcf6LDOgpgnwJrwBbX3f5toSiyR4vr6QT1434dWC81AQWobW16A2ZDpraulEKTz6Ad4ZFyXubi7TfUicogJiylMKXN69V2FsuwUfinOyAqiGC4gky7oIUfzyyLR95qIOycvnZOqlpBUXHa7KRORl1Gm9q8F2afcxWMncGrNCdQRuDgg0nsczgFDdkcNWqV1IVRVQW945fThHhjHQIXky48gojT8WF7GkXEYQiFeq0Lf1jkNEN2lOOUeTVPneQXyxMHpi0pY8YyfjjV5GYjFeqlu0pRfgCNeTP1sdwca7egKcYCIHTDnxptJjO3kbz5Fks04TiZoM4zbhbklcAmhqyRSLiboLFe7ZmaNLewO2mzoYfCkFBrgpwDYV2PfY75RE3VZ4MtUnAw0R2LlfAKXKMeOzObJ3CXTin5KuRHdOeMoLqtkFsDQvAFIgbzAT8r6dRvKzM9hm9dphT00V3KGOz9mQZVUsrfLUYUSc8uvbLeyIdO4yl6QAncXcfEZV86ydEqHJLJFXTBYRf2hX3tXCiB5GcHwaS5tmaF2bw5BnuDpRIWh0JEIjN1vj0UvBwYJ9E5vO1s2N0xMTaTe6XLubLFGHqedPmRXLgGivtWxE3wzAcKK8fpQidLYA8ipOTtnwVRtxI0rJk4";
        EQUALS(zpl_strlen(testString), 1000);
    });

//////////////// zpl_strncmp

    IT("can compare NULL strings", {
        SKIP();
        EQUALS(zpl_strcmp(NULL, NULL), 0);
    });

    IT("can compare empty strings", {
        EQUALS(zpl_strcmp("", ""), 0);
    });

    IT("can compare equal strings", {
        char testString[] = "4yISTS2afHajVqlCW1i9myvtdXfjAVT1v7p7aNLRQE64iS6Uzd8V79WIebfDmeTKa598JZzebEvG2bS5dZWGVurnRUfXynzp9KUYF6H4TcAn4rgunMVqXgEABujB9zICeKWwVuy8u44MkBPIJohmvbJA1pX6UzfXwdnXcHRi0mq3c5CXVn2pRRZ5Q61qjplYPH02JWlHOqn1GffW8ZtNyambylm62oBqJAj5jneJoyTuyHp45q16Qpu71EXL6v0EzsGyie0WqQPIWZyhhw7Kby199DrYcAJWz5JpWYBoN2DLvrKJRPO7ml2l1FqH3bjxQ7oS8QVVML5JdSOzmsysGXXWhs97hcWcf6LDOgpgnwJrwBbX3f5toSiyR4vr6QT1434dWC81AQWobW16A2ZDpraulEKTz6Ad4ZFyXubi7TfUicogJiylMKXN69V2FsuwUfinOyAqiGC4gky7oIUfzyyLR95qIOycvnZOqlpBUXHa7KRORl1Gm9q8F2afcxWMncGrNCdQRuDgg0nsczgFDdkcNWqV1IVRVQW945fThHhjHQIXky48gojT8WF7GkXEYQiFeq0Lf1jkNEN2lOOUeTVPneQXyxMHpi0pY8YyfjjV5GYjFeqlu0pRfgCNeTP1sdwca7egKcYCIHTDnxptJjO3kbz5Fks04TiZoM4zbhbklcAmhqyRSLiboLFe7ZmaNLewO2mzoYfCkFBrgpwDYV2PfY75RE3VZ4MtUnAw0R2LlfAKXKMeOzObJ3CXTin5KuRHdOeMoLqtkFsDQvAFIgbzAT8r6dRvKzM9hm9dphT00V3KGOz9mQZVUsrfLUYUSc8uvbLeyIdO4yl6QAncXcfEZV86ydEqHJLJFXTBYRf2hX3tXCiB5GcHwaS5tmaF2bw5BnuDpRIWh0JEIjN1vj0UvBwYJ9E5vO1s2N0xMTaTe6XLubLFGHqedPmRXLgGivtWxE3wzAcKK8fpQidLYA8ipOTtnwVRtxI0rJk4";
        char testString2[] = "4yISTS2afHajVqlCW1i9myvtdXfjAVT1v7p7aNLRQE64iS6Uzd8V79WIebfDmeTKa598JZzebEvG2bS5dZWGVurnRUfXynzp9KUYF6H4TcAn4rgunMVqXgEABujB9zICeKWwVuy8u44MkBPIJohmvbJA1pX6UzfXwdnXcHRi0mq3c5CXVn2pRRZ5Q61qjplYPH02JWlHOqn1GffW8ZtNyambylm62oBqJAj5jneJoyTuyHp45q16Qpu71EXL6v0EzsGyie0WqQPIWZyhhw7Kby199DrYcAJWz5JpWYBoN2DLvrKJRPO7ml2l1FqH3bjxQ7oS8QVVML5JdSOzmsysGXXWhs97hcWcf6LDOgpgnwJrwBbX3f5toSiyR4vr6QT1434dWC81AQWobW16A2ZDpraulEKTz6Ad4ZFyXubi7TfUicogJiylMKXN69V2FsuwUfinOyAqiGC4gky7oIUfzyyLR95qIOycvnZOqlpBUXHa7KRORl1Gm9q8F2afcxWMncGrNCdQRuDgg0nsczgFDdkcNWqV1IVRVQW945fThHhjHQIXky48gojT8WF7GkXEYQiFeq0Lf1jkNEN2lOOUeTVPneQXyxMHpi0pY8YyfjjV5GYjFeqlu0pRfgCNeTP1sdwca7egKcYCIHTDnxptJjO3kbz5Fks04TiZoM4zbhbklcAmhqyRSLiboLFe7ZmaNLewO2mzoYfCkFBrgpwDYV2PfY75RE3VZ4MtUnAw0R2LlfAKXKMeOzObJ3CXTin5KuRHdOeMoLqtkFsDQvAFIgbzAT8r6dRvKzM9hm9dphT00V3KGOz9mQZVUsrfLUYUSc8uvbLeyIdO4yl6QAncXcfEZV86ydEqHJLJFXTBYRf2hX3tXCiB5GcHwaS5tmaF2bw5BnuDpRIWh0JEIjN1vj0UvBwYJ9E5vO1s2N0xMTaTe6XLubLFGHqedPmRXLgGivtWxE3wzAcKK8fpQidLYA8ipOTtnwVRtxI0rJk4";
        
        EQUALS(zpl_strcmp(testString, testString2), 0);
    });

    IT("can compare different strings", {
        char testString[] = "4yISTS2afHajVqlCW1i9myvtdXfjAVT1v7p7aNLRQE64iS6Uzd8V79WIebfDmeTKa598JZzebEvG2bS5dZWGVurnRUfXynzp9KUYF6H4TcAn4rgunMVqXgEABujB9zICeKWwVuy8u44MkBPIJohmvbJA1pX6UzfXwdnXcHRi0mq3c5CXVn2pRRZ5Q61qjplYPH02JWlHOqn1GffW8ZtNyambylm62oBqJAj5jneJoyTuyHp45q16Qpu71EXL6v0EzsGyie0WqQPIWZyhhw7Kby199DrYcAJWz5JpWYBoN2DLvrKJRPO7ml2l1FqH3bjxQ7oS8QVVML5JdSOzmsysGXXWhs97hcWcf6LDOgpgnwJrwBbX3f5toSiyR4vr6QT1434dWC81AQWobW16A2ZDpraulEKTz6Ad4ZFyXubi7TfUicogJiylMKXN69V2FsuwUfinOyAqiGC4gky7oIUfzyyLR95qIOycvnZOqlpBUXHa7KRORl1Gm9q8F2afcxWMncGrNCdQRuDgg0nsczgFDdkcNWqV1IVRVQW945fThHhjHQIXky48gojT8WF7GkXEYQiFeq0Lf1jkNEN2lOOUeTVPneQXyxMHpi0pY8YyfjjV5GYjFeqlu0pRfgCNeTP1sdwca7egKcYCIHTDnxptJjO3kbz5Fks04TiZoM4zbhbklcAmhqyRSLiboLFe7ZmaNLewO2mzoYfCkFBrgpwDYV2PfY75RE3VZ4MtUnAw0R2LlfAKXKMeOzObJ3CXTin5KuRHdOeMoLqtkFsDQvAFIgbzAT8r6dRvKzM9hm9dphT00V3KGOz9mQZVUsrfLUYUSc8uvbLeyIdO4yl6QAncXcfEZV86ydEqHJLJFXTBYRf2hX3tXCiB5GcHwaS5tmaF2bw5BnuDpRIWh0JEIjN1vj0UvBwYJ9E5vO1s2N0xMTaTe6XLubLFGHqedPmRXLgGivtWxE3wzAcKK8fpQidLYA8ipOTtnwVRtxI0rJk4";
        char testString2[] = "4yISTS2afHajVqlCW1i9myvtdXfjAVT1v7p7aNLRQE64iS6Uzd8V79WIebfDmeTKa598JZzebEvG2bS5dZWGVurnRUfXynzp9KUYF6H4TcAn4rgunMVqXgEABujB9zICeKWwVuy8u44MkBPIJohmvbJA1pX6UzfXwdnXcHRi0mq3c5CXVn2pRRZ5Q61qjplYPH02JWlHOqn1GffW8ZtNyambylm62oBqJAj5jneJoyTuyHp45q16Qpu71EXL6v0EzsGyie0WqQPIWZyhhw7Kby199DrYcAJWz5JpWYBoN2DLvrKJRPO7ml2l1FqH3bjxQ7oS8QVVML5JdSOzmsysGXXWhs97hcWcf6LDOgpgnwJrwBbX3f5toSiyR4vr6QT1434dWC81AQWobW16A2ZDpraulEKTz6Ad4ZFyXubi7TfUicogJiylMKXN69V2FsuwUfinOyAqiGC4gky7oIUfzyyLR95qIOycvnZOqlpBUXHa7KRORl1Gm9q8F2afcxWMncGrNCdQRuDgg0nsczgFDdkcNWqV1IVRVQW945fThHhjHQIXky48gojT8WF7GkXEYQiFeq0Lf1jkNEN2lOOUeTVPneQXyxMHpi0pY8YyfjjV5GYjFeqlu1pRfgCNeTP1sdwca7egKcYCIHTDnxptJjO3kbz5Fks04TiZoM4zbhbklcAmhqyRSLiboLFe7ZmaNLewO2mzoYfCkFBrgpwDYV2PfY75RE3VZ4MtUnAw0R2LlfAKXKMeOzObJ3CXTin5KuRHdOeMoLqtkFsDQvAFIgbzAT8r6dRvKzM9hm9dphT00V3KGOz9mQZVUsrfLUYUSc8uvbLeyIdO4yl6QAncXcfEZV86ydEqHJLJFXTBYRf2hX3tXCiB5GcHwaS5tmaF2bw5BnuDpRIWh0JEIjN1vj0UvBwYJ9E5vO1s2N0xMTaTe6XLubLFGHqedPmRXLgGivtWxE3wzAcKK8fpQidLYA8ipOTtnwVRtxI0rJk4";

        NEQUALS(zpl_strcmp(testString, testString2), 1);
    });

    IT("can compare short string with long string", {
        char testString[] = "4yISTS2afHajVqlCW1i9myvt";
        char testString2[] = "4yISTS2afHajVqlCW1i9myvtdXfjAVT1v7p7aNLRQE64iS6Uzd8V79WIebfDmeTKa598JZzebEvG2bS5dZWGVurnRUfXynzp9KUYF6H4TcAn4rgunMVqXgEABujB9zICeKWwVuy8u44MkBPIJohmvbJA1pX6UzfXwdnXcHRi0mq3c5CXVn2pRRZ5Q61qjplYPH02JWlHOqn1GffW8ZtNyambylm62oBqJAj5jneJoyTuyHp45q16Qpu71EXL6v0EzsGyie0WqQPIWZyhhw7Kby199DrYcAJWz5JpWYBoN2DLvrKJRPO7ml2l1FqH3bjxQ7oS8QVVML5JdSOzmsysGXXWhs97hcWcf6LDOgpgnwJrwBbX3f5toSiyR4vr6QT1434dWC81AQWobW16A2ZDpraulEKTz6Ad4ZFyXubi7TfUicogJiylMKXN69V2FsuwUfinOyAqiGC4gky7oIUfzyyLR95qIOycvnZOqlpBUXHa7KRORl1Gm9q8F2afcxWMncGrNCdQRuDgg0nsczgFDdkcNWqV1IVRVQW945fThHhjHQIXky48gojT8WF7GkXEYQiFeq0Lf1jkNEN2lOOUeTVPneQXyxMHpi0pY8YyfjjV5GYjFeqlu1pRfgCNeTP1sdwca7egKcYCIHTDnxptJjO3kbz5Fks04TiZoM4zbhbklcAmhqyRSLiboLFe7ZmaNLewO2mzoYfCkFBrgpwDYV2PfY75RE3VZ4MtUnAw0R2LlfAKXKMeOzObJ3CXTin5KuRHdOeMoLqtkFsDQvAFIgbzAT8r6dRvKzM9hm9dphT00V3KGOz9mQZVUsrfLUYUSc8uvbLeyIdO4yl6QAncXcfEZV86ydEqHJLJFXTBYRf2hX3tXCiB5GcHwaS5tmaF2bw5BnuDpRIWh0JEIjN1vj0UvBwYJ9E5vO1s2N0xMTaTe6XLubLFGHqedPmRXLgGivtWxE3wzAcKK8fpQidLYA8ipOTtnwVRtxI0rJk4";

        EQUALS(zpl_strcmp(testString, testString2), 1);
    });

    IT("can compare long string with short string", {
        char testString[] = "4yISTS2afHajVqlCW1i9myvtdXfjAVT1v7p7aNLRQE64iS6Uzd8V79WIebfDmeTKa598JZzebEvG2bS5dZWGVurnRUfXynzp9KUYF6H4TcAn4rgunMVqXgEABujB9zICeKWwVuy8u44MkBPIJohmvbJA1pX6UzfXwdnXcHRi0mq3c5CXVn2pRRZ5Q61qjplYPH02JWlHOqn1GffW8ZtNyambylm62oBqJAj5jneJoyTuyHp45q16Qpu71EXL6v0EzsGyie0WqQPIWZyhhw7Kby199DrYcAJWz5JpWYBoN2DLvrKJRPO7ml2l1FqH3bjxQ7oS8QVVML5JdSOzmsysGXXWhs97hcWcf6LDOgpgnwJrwBbX3f5toSiyR4vr6QT1434dWC81AQWobW16A2ZDpraulEKTz6Ad4ZFyXubi7TfUicogJiylMKXN69V2FsuwUfinOyAqiGC4gky7oIUfzyyLR95qIOycvnZOqlpBUXHa7KRORl1Gm9q8F2afcxWMncGrNCdQRuDgg0nsczgFDdkcNWqV1IVRVQW945fThHhjHQIXky48gojT8WF7GkXEYQiFeq0Lf1jkNEN2lOOUeTVPneQXyxMHpi0pY8YyfjjV5GYjFeqlu1pRfgCNeTP1sdwca7egKcYCIHTDnxptJjO3kbz5Fks04TiZoM4zbhbklcAmhqyRSLiboLFe7ZmaNLewO2mzoYfCkFBrgpwDYV2PfY75RE3VZ4MtUnAw0R2LlfAKXKMeOzObJ3CXTin5KuRHdOeMoLqtkFsDQvAFIgbzAT8r6dRvKzM9hm9dphT00V3KGOz9mQZVUsrfLUYUSc8uvbLeyIdO4yl6QAncXcfEZV86ydEqHJLJFXTBYRf2hX3tXCiB5GcHwaS5tmaF2bw5BnuDpRIWh0JEIjN1vj0UvBwYJ9E5vO1s2N0xMTaTe6XLubLFGHqedPmRXLgGivtWxE3wzAcKK8fpQidLYA8ipOTtnwVRtxI0rJk4";
        char testString2[] = "4yISTS2afHajVqlCW1i9myvt";

        EQUALS(zpl_strcmp(testString, testString2), -1);
    });

//////////////// zpl_strcpy
    
    IT("copy NULL string to NULL destination", {
        SKIP();
        EQUALS(zpl_strcpy(NULL, NULL), NULL);
    });

    IT("copy NULL string to non NULL destination", {
        char dest[128];

        EQUALS(zpl_strcpy(dest, NULL), NULL);
    });

    IT("copy non null string to NULL destination", {
        char source[] = "sourcestring";
        EQUALS(zpl_strcpy(NULL, source), NULL);
    });
    
    IT("copy a string to a destination shorter than the string", {});


//////////////// zpl_strcat
//////////////// zpl_strncpy
//////////////// zpl_strlcpy
//////////////// zpl_strrev
//////////////// zpl_strtok
//////////////// zpl_strntok
//////////////// zpl_strdup
//////////////// zpl_str_split_lines
//////////////// zpl_str_has_prefix
//////////////// zpl_str_has_suffix
//////////////// zpl_char_first_occurence
//////////////// zpl_char_last_occurence
//////////////// zpl_str_concat
//////////////// zpl_str_to_u64
//////////////// zpl_str_to_i64
//////////////// zpl_str_to_f64
//////////////// zpl_i64_to_str
//////////////// zpl_u64_to_str
// 
//////////////// zpl_str_to_f32
// NULL string
// non float
// float
// float too long
// float with text mixed in

//////////////// zpl_utf8_strlen
//////////////// zpl_utf8_strnlen
//////////////// zpl_utf8_to_ucs2
//////////////// zpl_ucs2_to_utf8
//////////////// zpl_utf8_to_ucs2_buf
//////////////// zpl_ucs2_to_utf8_buf
//////////////// zpl_utf8_decode
//////////////// zpl_utf8_codepoint_size
//////////////// zpl_utf8_encode_rune

});

