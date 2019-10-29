use strict;
use warnings;

open IN, "<./scratchpad.txt" or die;
my @lines = <IN>;
close IN;

my $content = "";
for my $line (@lines) {
	$content = $content . wrapText($line);
}

$content =~ s/\n{2,}/\n/g;
$content =~ s/Example/\nExample/g;
$content =~ s/\n{2,}Example/\n\nExample/g;

$content =~ s/Note/\nNote/g;
$content =~ s/\n{2,}Note/\n\nNote/g;

$content =~ s/NOTE/\nNOTE/g;
$content =~ s/\n{2,}NOTE/\n\nNOTE/g;
$content =~ s/\n/\n\/\//g;

open OUT, ">./scratchpad.txt" or die;
print OUT $content;
close OUT;

print "\n\n\nCompleted!\n\n";


 sub wrapText{
	my $text = shift;
	my $max = 80;
	
	my $result = "";
	while ($text) {
	    if (length $text <= $max) {
	        $result = $result . "\n". $text;
	        last;
	    }
	    my $prefix = substr $text, 0, $max;
	    my $loc = rindex $prefix, ' ';
	 
	    if ($loc == -1) {
	        die "We found a word which is longer than $max\n";
	    }
	    my $str = substr $text, 0, $loc, '';
	   	$result = $result . "\n". $str;
	    substr $text, 0, 1, '';
	} 	
    return $result;
 }