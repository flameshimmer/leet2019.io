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
<h1>Ning\'s Review Page</h1>
<ol>
';

my %hashset = ();
my $index = 0;
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
		$content = $content . "\t\t<li><a href=\"$url\">$problemName</a></li>\n";
		if ($index > 0 && $index % 10 == 0) {$content = $content . "<hr>"}
		$index ++;
		#createProblemWebPage($problemName);
	}
}

$content = $content . "</ol>\n</body>\n</html>\n";

open OUT, ">index.html" or die;
print OUT $content;
close OUT;
print "\n\nCompleted!\n\n";


sub createProblemWebPage {
	my $subpageHeaderTemplate = '<!doctype html>
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
	<title>$$PROBLEM_NAME$$</title>
	<!-- Latest compiled and minified CSS -->
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css" integrity="sha384-HSMxcRTRxnN+Bdg0JdbxYKrThecOKuH5zCYotlSAcp1+c8xmyTe9GYg1l9a69psu" crossorigin="anonymous">

	<!-- Optional theme -->
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap-theme.min.css" integrity="sha384-6pzBo3FDv/PJ8r2KRkGHifhEocL+1X2rVCTTkUfGk7/0pbek5mMa1upzvWbrUbOZ" crossorigin="anonymous">

	<!-- Latest compiled and minified JavaScript -->
	<script src="https://stackpath.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js" integrity="sha384-aJ21OjlMXNL5UyIl/XNwTMqvzeRMZH2w8c5cRVpzpU8Y5bApTppSuUkhZXN0VxHd" crossorigin="anonymous"></script>

	<link rel="stylesheet" href="../web/codepage.css" />
	</head>
	<body>
	<h1>$$PROBLEM_NAME$$</h1>
	';

	my $subpageFooterTemplate = '
	</body>
	</html>
	';

	my $codeblockTemplate = '
	<figure class="highlight">
	<pre>
	<code class="language-html">
$$CODE$$
	</code>
	</pre>
	</figure>
	';

	my $filename = shift;
	open IN, "<C:\\Users\\flame\\OneDrive\\Desktop\\code\\Leet2019\\$filename.cpp" or die "can't open $filename.cpp!: $!";
	my @lines = <IN>;
	close IN;

	my $line = join('', @lines);
	$line =~ s/</&lt;/g;
	$line =~ s/>/&gt;/g;


	my $content = $codeblockTemplate;
	$content =~ s/\$\$CODE\$\$/$line/g;
	$content = $subpageHeaderTemplate . $content . $subpageFooterTemplate;
	$content =~ s/\$\$PROBLEM_NAME\$\$/$filename/g;



	open OUT, ">./code/$filename.html" or die;
	print OUT $content;
	close OUT;
}