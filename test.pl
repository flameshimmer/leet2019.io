use strict;
use warnings;

 
 sub wrapText{
	my $text = shift;
	my $max = 80;
	 
	while ($text) {
	    if (length $text <= $max) {
	        say $text;
	        last;
	    }
	    my $prefix = substr $text, 0, $max;
	    my $loc = rindex $prefix, ' ';
	 
	    if ($loc == -1) {
	        die "We found a word which is longer than $max\n";
	    }
	    my $str = substr $text, 0, $loc, '';
	    say $str;
	    substr $text, 0, 1, '';
	} 	
 }

