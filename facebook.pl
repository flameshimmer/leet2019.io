use strict;
use warnings;
use Time::localtime;
use File::stat;

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
<h1>Ning\'s Facebook study page</h1>
<ol>
';

my @lines;


my %hash = ();
my $filedir = "./Leet2019";

opendir(my $dir, $filedir) or die "Could not load directory";
my @read_dir = sort grep {!-d}readdir($dir);
foreach my $fileInDir(@read_dir)
{

    my $fh = "$filedir/$fileInDir";
	my $timestamp = ctime(stat($fh)->mtime);
	#print "Filename: $fileInDir modtime: $timestamp\n";
    if ($timestamp !~ m/Wed Sep  4 19:52:\d+ 2019/)
    {        
        $fileInDir =~ s/\.cpp//g;
        $hash{$fileInDir} = 1;
    } else {
    	#print "Empty file! $fileInDir\n";
    }
}

=pod


open IN, "<index.html" or die;
my @lines = <IN>;
close IN;


#<li><a href="./code/ValidParentheses.html">ValidParentheses</a></li>
for my $line (@lines) {
	if ($line =~ m/.*<li><a.*>(.*)<\/a><\/li>/) {
		my $p = $1;
		$hash{$p} = 1;
	}
}

=cut
open IN, "<facebook.data" or die;
@lines = <IN>;
close IN;


my $index = 0;
my $lineNum = 0;
#K Closest Points to Origin	61.6%	Medium	
for my $line (@lines) {
	if ($line =~ m/(.*)\s+[\d|\.]+%/) {
		my $question = $1;
		$question =~ s/\s//g;
		$question =~ s/\-//g;
		$question =~ s/\'//g;
		$question =~ s/\://g;
		$question =~ s/\`//g;
		$question =~ s/\(.*\)//g;
		$question =~ s/\=//g;
		$question =~ s/\?//g;
		$question =~ s/3/Three/g;
		$question =~ s/2/Two/g;
		$question =~ s/4/Four/g;
		$question =~ s/1/One/g;
		$question =~ s/5/Five/g;
		$question =~ s/6/Six/g;
		$question =~ s/7/Seven/g;
		$question =~ s/8/Eight/g;
		$question =~ s/9/Nine/g;
		$question =~ s/0/Zero/g;

		if (!exists $hash{$question}) {print "Can't find question: $question\n";}
		my $url = './code/' . $question . '.html'; 
		$content = $content . "\t\t<li><a href=\"$url\">$index - $question</a></li>\n";
	} elsif ($line =~ m/(\d+)[\t|\s]*/) {
		$index = $1;		
	}
	$lineNum++;
}
$content = $content . "</ol>\n</body>\n</html>\n";


open OUT, ">facebook.html" or die;
print OUT $content;
close OUT;


print "\n\nCompleted!\n\n\n";