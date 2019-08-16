use strict;
use warnings;

open IN, "<./data" or die;
my @lines = <IN>;
close IN;

my $template="#include \"stdafx.h\"
// 

namespace Solution2019
{
	namespace \$\$PROBLEM\$\$
	{
		void Main() {
			string test = \"tst test test\";
			print(test);
		}
	}
}

";

open OUT1, ">./out1" or die;
open OUT2, ">./out2" or die;
for my $line (@lines)
{
	chomp $line;
	if ($line !~ m/^\s*\d*\s*$/)
	{
		$line =~ s/\s//g;
		$line =~ s/\-//g;
		$line =~ s/\'//g;
		$line =~ s/\://g;
		$line =~ s/\`//g;
		$line =~ s/\(.*\)//g;
		$line =~ s/\=//g;
		$line =~ s/3/Three/g;
		$line =~ s/2/Two/g;
		$line =~ s/4/Four/g;
		$line =~ s/1/One/g;
		$line =~ s/5/Five/g;
		$line =~ s/6/Six/g;
		$line =~ s/7/Seven/g;
		$line =~ s/8/Eight/g;
		$line =~ s/9/Nine/g;
		$line =~ s/0/Zero/g;
		print "$line\n";
		print OUT1 "//Solution2019::". $line."::Main();\n";
		print OUT2 "namespace ". $line."{ void Main(); }\n";
		my $content = $template;
		$content =~ s/\$\$PROBLEM\$\$/$line/g;
		my $cppFileName = "C:\\Users\\Administrator\\Desktop\\leet2019\\Leet2019\\" . $line . ".cpp";
		print "$cppFileName\n";
		open OUT, ">$cppFileName" or die "Can't open file $cppFileName for write!\n";
		print OUT $content;
		close OUT;
	}
}

print "\n\nCompleted!\n\n\n";