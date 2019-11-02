use strict;
use warnings;

open IN, "<C:\\Users\\flame\\OneDrive\\Desktop\\code\\Leet2019\\Leet2019.cpp" or die "can't open Leet2019.cpp!: $!";
my @lines = <IN>;
close IN;

=pod
	//8/25/2019
	//Solution2019::LongestCommonPrefix::Main();
	//Solution2019::ValidParentheses::Main();
	//Solution2019::MergeTwoSortedLists::Main();
	//Solution2019::RemoveDuplicatesfromSortedArray::Main();
=cut
my $start = 0;
my @daily = ();
my $date="";

my $content = '<!doctype html>
<html>
<head>
<title>Ning\'s study page</title>
<!-- Latest compiled and minified CSS -->
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css" integrity="sha384-HSMxcRTRxnN+Bdg0JdbxYKrThecOKuH5zCYotlSAcp1+c8xmyTe9GYg1l9a69psu" crossorigin="anonymous">

<!-- Optional theme -->
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap-theme.min.css" integrity="sha384-6pzBo3FDv/PJ8r2KRkGHifhEocL+1X2rVCTTkUfGk7/0pbek5mMa1upzvWbrUbOZ" crossorigin="anonymous">

<!-- Latest compiled and minified JavaScript -->
<script src="https://stackpath.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js" integrity="sha384-aJ21OjlMXNL5UyIl/XNwTMqvzeRMZH2w8c5cRVpzpU8Y5bApTppSuUkhZXN0VxHd" crossorigin="anonymous"></script>

<link rel="stylesheet" href="./web/index.css" />
</head>
<body>
<h1>Ning\'s Studdy Page</h1>
';


for my $line (@lines) {
	if ($line =~ m/^\s*\/\/(\d+\/\d+\/\d+)\s*$/) {
		my $newdate = $1;
		if ($date eq "") {$date = $newdate;}
		#print $line;
		$start = 1;
		if (scalar @daily > 0) {
			$content = $content . "\n<h2>$date<h2>\n\t<ul>\n";
			for my $p (@daily) {
				if ($p =~ m/.*::(.*)::Main/) {
					my $pn = $1;
					my $url = 'https://github.com/flameshimmer/leet2019/blob/master/Leet2019/' . $pn . '.cpp'; 
					$content = $content . "\t\t<li><a href=\"$url\">$pn</a></li>\n";
				}else {
					print "wtf - $p\n";
				}
			}
			$content = $content . "\t</ul>";
		}
		@daily = ();
		$date = $newdate;
	}
	elsif ($line =~ m/Problem Ends/) {
		$start = 0;
		if (scalar @daily > 0) {
			$content = $content . "\n<h2>$date<h2>\n\t<ul>\n";
			for my $p (@daily) {
				if ($p =~ m/.*::(.*)::Main/) {
					my $pn = $1;
					my $url = 'https://github.com/flameshimmer/leet2019/blob/master/Leet2019/' . $pn . '.cpp'; 
					$content = $content . "\t\t<li><a href=\"$url\">$pn</a></li>\n";
				}else {
					print "wtf - $p\n";
				}
			}
			$content = $content . "\t</ul>";
		}		
	}
	elsif ($start == 1 && $line !~ m/^\s*$/) {
		push(@daily, $line);
	}
}
$content = $content . "\n</body>\n</html>\n";

open OUT, ">index.html" or die;
print OUT $content;
close OUT;