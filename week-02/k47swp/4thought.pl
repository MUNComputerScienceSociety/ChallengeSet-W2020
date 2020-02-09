#!/usr/bin/env perl

use strict;
use warnings;

my @ops       = split("", "+-*/");
my $operators = scalar(@ops);
my $value     = "4";
my $n         = <>+0;

foreach (1 .. $n) {
  my $target = <>+0;
  my $equation;
  my $answer = "no solution";
    
  FIND_EQUATION: {
    for (my $i = 0 ; $i < $operators ; $i++) {
      for (my $j = 0 ; $j < $operators ; $j++) {
        for (my $k = 0 ; $k < $operators ; $k++) {
          $equation = $value.$ops[$i].$value.$ops[$j].$value.$ops[$k].$value;
          if (eval_equation($equation) == $target) {
            $answer = join(" ", split("", $equation))." = ".$target;
            last FIND_EQUATION;
          }
        }
      }
    }
  }
  print $answer. "\n";
}

sub eval_equation {
  my @equation = split("", $_[0]);
  my $position = 1;

  while ($position < @equation) {
    my $left  = $equation[$position-1];
    my $op    = $equation[$position];
    my $right = $equation[$position+1];
 
    if ("/" eq $op) {
      $equation[$position-1] = int($left/$right);
      splice(@equation, $position, 2);
      $position = 1;
    }

    elsif ("*" eq $op) {
      $equation[$position-1] = $left*$right;
      splice(@equation, $position, 2);
      $position = 1;
    }

    else {
      $position += 2;  
    }
  }
  
  $position = 1;
  while ($position < @equation) {
    my $left  = $equation[$position-1];
    my $op    = $equation[$position];
    my $right = $equation[$position+1];
      
    if ("+" eq $op) {
      $equation[$position-1] = int($left+$right);
      splice(@equation, $position, 2);
      $position = 1;
    }

    elsif ("-" eq $op) {
      $equation[$position-1] = $left-$right;
      splice(@equation, $position, 2);
      $position = 1;
    }

    else {
      $position += 2;  
    }
  }
  return $equation[0];
}
