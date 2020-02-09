#!/usr/bin/env perl

use strict;

my $n = <> + 0;

foreach (1..$n) {
  my $a = length <>;
  print --$a . "\n";
}
