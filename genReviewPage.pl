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
my @all = ();

my $content = '<!doctype html>
<html>
<head>
<!-- Global site tag (gtag.js) - Google Analytics -->
<script async src="https://www.googletagmanager.com/gtag/js?id=UA-151395790-1"></script>
<script>
  window.dataLayer = window.dataLayer || [];
  function gtag(){dataLayer.push(arguments);}
  gtag(\'js\', new Date());

  gtag(\'config\', \'UA-151395790-1\');
</script>

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
<h1>Ning\'s FB study Page</h1>
<ul><li><a href=\"fackbook.html\">Fackbook study page</a></li></ul>
<h1>Ning\'s Review Page</h1>
<ol>
';

my %hashset = ();
my @allProblems = ();

#//Solution2019::MarketAnalysisII::Main();
for my $line (@lines) {
	if ($line =~ m/Problem Starts/) {
		$start = 1;
	}
	elsif ($line =~ m/Problem Ends/) {
		$start = 0;
	}
	elsif ($start == 1 && $line =~ m/Solution2019::(.*)::/) {
		my $problemName = $1;
		if (exists $hashset{$problemName}) {next;}
		$hashset{$problemName} = 1;	
		my $url = './code/' . $problemName . '.html'; 
		push(@allProblems,  "\t\t<li><a href=\"$url\">$problemName</a></li>\n");
	}
}

@allProblems = sort @allProblems;

for my $p (@allProblems) {
	$content = $content . $p;
}

$content = $content . "</ol>\n</body>\n</html>\n";

open OUT, ">index.html" or die;
print OUT $content;
close OUT;
print "\n\nCompleted!\n\n";

