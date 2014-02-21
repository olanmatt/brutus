brutus
======

brutus is a CLI brute-force tool used to generate permutations of a character set. This is perticularly useful when brute-forcing passwords, or hashes from the command line.

Usage
-----

brutus is ready to go right away with commonly used character sets and other settings. For example,

	$ brutus

will generate all permutations of the `mixalpha-numeric-all` character set, with a minimum length of 1, and a maximum length of 7.

For usage documentation, use

	$ brutus --help

For version information, use

	$ brutus --version

These settings are quickly and easily customizable from the command line, allowing you to change the length requirements and character sets quickly.

	$ brutus --charset numeric --min 5 --max 20

This will generate all numeric permutations of length 5 to 20, and can also be written as,

	$ brutus -c numeric -m 5 -M 20

brutus will (not yet implemented) also allow for permutation without replacement for brute-forcing over a more specific character set, or for solving anagrams :).

Character set definitions are as follows (found in `charset.txt`),

	byte                        = [0x00 ... 0xFF]
	alpha                       = [ABCDEFGHIJKLMNOPQRSTUVWXYZ]
	alpha-space                 = [ABCDEFGHIJKLMNOPQRSTUVWXYZ ]
	alpha-numeric               = [ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789]
	alpha-numeric-space         = [ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ]
	alpha-numeric-symbol14      = [ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=]
	alpha-numeric-symbol14-space= [ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+= ]
	all                         = [ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=~`[]{}|\:;"'<>,.?/]
	all-space                   = [ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=~`[]{}|\:;"'<>,.?/ ]
	alpha-numeric-symbol32-space = [ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=~`[]{}|\:;"'<>,.?/ ]
	lm-frt-cp437                = [ !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`{|}~�����������������������]
	lm-frt-cp850                = [ !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`{|}~�������������������������������������]
	lm-frt-cp437-850            = [ !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`{|}~������������������������������������������]
	numeric                     = [0123456789]
	numeric-space               = [0123456789 ]
	loweralpha                  = [abcdefghijklmnopqrstuvwxyz]
	loweralpha-space            = [abcdefghijklmnopqrstuvwxyz ]
	loweralpha-numeric          = [abcdefghijklmnopqrstuvwxyz0123456789]
	loweralpha-numeric-space    = [abcdefghijklmnopqrstuvwxyz0123456789 ]
	loweralpha-numeric-symbol14 = [abcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_+=]
	loweralpha-numeric-all         = [abcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_+=~`[]{}|\:;"'<>,.?/]
	loweralpha-numeric-symbol32-space= [abcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_+=~`[]{}|\:;"'<>,.?/ ]
	mixalpha                    = [abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]
	mixalpha-space              = [abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ]
	mixalpha-numeric            = [abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789]
	mixalpha-numeric-space      = [abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ]
	mixalpha-numeric-symbol14   = [abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=]
	mixalpha-numeric-all        = [abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=~`[]{}|\:;"'<>,.?/]
	mixalpha-numeric-symbol32-space  = [abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=~`[]{}|\:;"'<>,.?/ ]
	mixalpha-numeric-all-space  = [abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=~`[]{}|\:;"'<>,.?/ ]
