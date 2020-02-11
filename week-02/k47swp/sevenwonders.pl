#!/usr/bin/env perl

use strict;

foreach (<STDIN>) {
  my ($c, $g, $t) = (0, 0, 0);
  foreach my $x (split('')) {
    if ($x =~ m/c/i) { $c++; }
    if ($x =~ m/g/i) { $g++; }
    if ($x =~ m/t/i) { $t++; }
  }
  
  my $sum = $c*$c + $g*$g + $t*$t;
  
  my $bonus = 0;
  while ($c>0 && $g>0 && $t>0) {
    $bonus += 7;
    $c--; $g--; $t--;
  }

  print $sum+$bonus . "\n";
}
