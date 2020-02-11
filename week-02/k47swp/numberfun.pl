#!/usr/bin/env perl

use strict;
use warnings;

my $n = <> + 0;

foreach (1..$n) {
  my ($a,$b,$c) = split (' ', <>);
  if ($a*$b==$c || $a+$b==$c ||
      $a-$b==$c || $b-$a==$c ||
      $a/$b==$c || $b/$a==$c) {
    print "Possible\n";
  } else {
    print "Impossible\n";
  }
}