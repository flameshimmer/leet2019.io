use strict;
use warnings;

open IN, "<./scratchpad.txt" or die;
my @lines = <IN>;
close IN;

my $content = join "", @lines;


$content =~ s/\"/\'/g;
$content =~ s/\[/\{/g;
$content =~ s/\]/\}/g;

open OUT, ">./scratchpad.txt" or die;
print OUT "vector<vector<int>> test = ";
print OUT $content;
print OUT ";";
close OUT;

print "\n\n\nCompleted!\n\n";