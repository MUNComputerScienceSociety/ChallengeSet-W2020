#!/usr/bin/env perl

use strict;

foreach (<STDIN>) {
  if ($_ =~ m/^$|^([A-Z]{3}|[A-Z]{2} |[A-Z]  )\d{4}[A-Z]?$/) {
    print "Y\n";
  } else {
    print "N\n";
  }
}
