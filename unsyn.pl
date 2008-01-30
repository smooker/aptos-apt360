#!/usr/bin/perl -w

# Ed Dolan <bytecolor@yahoo.com>
# 01/20/2008

#
# Remove all APT SYN/ assignments.
#

use strict;

my (%synhash, $synre);
my $fixed = "remark|partno|pprint|insert|titles";
my $help = <<END_help;
Remove all the SYN/ assignments from an apt360 source file.
Usage: unsyn.pl foo.apt
       Output is to stdout.
Note: If an expanded statement is > 72 chars AND it ends in a
comment, the comment will be moved to the line preceding the
statement.
END_help
if (@ARGV && $ARGV[0] =~ /^((-h)|(--help))$/ ) {
    print  $help;
    exit 1;
}

while (<>) {
    chomp;
    # match a SYN/ statement
    if (/^\s*([a-z0-9]{1,6}\))?\s*syn\s*\/([a-z0-9,\s]+)(\$.*)?$/i) {
        my ($synstr, @synlist, %newhash);
        # could be: SYN/ $ with no arguments on this line.
        # fscked yes, but possible...
        if ($2) { $synstr .= $2; }
        # comment out the SYN/ statement
        print "\$\$ $_\n";
        # continuation?
        if ($3) {
            while (<>) {
                chomp;
                # comment or blank line terminates a requested continuation
                if (/^\s*\$\s*\$/ || /^$/) {
                    print "$_\n";
                    last;
                }
                # only a continuation on the line with optional comment suffix
                elsif (/^\s*\$.*/) {
                    print "\$\$ $_\n";
                    next;
                }
                # might be an illegal continued line
                elsif (/^($fixed)|([^a-z0-9,\$\s]+)/i) {
                    die "suspicious continued line:\n$_\n";
                }
                # XXX goofy re
                elsif (/^(\s+)?([a-z0-9,\s]+)(\$.*)?$/i) {
                    $synstr .= $2;
                    # comment out the SYN/ statement
                    print "\$\$ $_\n";
                    if ($3) { next; } else { last; }
                }
                else {
                    die "should not be here\n";
                }
            }
        }
        # assemble the hash, merging, if multiple SYN/ statements are found
        $synstr =~ tr/[ \t]//d;
        @synlist = split(/,/, $synstr);
        %newhash = split(/,/, $synstr);
        # swap the keys and values, if an APT keyword was
        # first in the list of pairs
        if (length $synlist[0] > length $synlist[1]) {
            %newhash = reverse %newhash;
        }
        # merge
        %synhash = (%synhash, %newhash);

        # XXX why doesn't this work?
        #$synhash{keys %newhash} = values %newhash;
        #print join("\n", keys %synhash);

        # re to match the defined synonyms
        $synre = "\\b(" . join("|", keys %synhash) . ")\\b";
    }
    else {
        if (%synhash) {
            unless (/^(($fixed)|(\s*\$\s*\$))/i) {
                s/$synre/$synhash{$1}/g;
                fit72($_) if length > 72;
            }
        }
        print "$_\n";
    }
}

# Dice a line > 72 characters up into 72-char-max chunks,
# including the $ continuation character.
# The APT processor does not care where I break the line.
# It can be in the middle of an identifier.
# The statement: point1 = point/ 0, 0
# could be:
# po$
# in                      $
# t1 = point/ 0, 0
sub fit72 {
    my ($i, @parts, $code, $comment, $chunk_size);
    $chunk_size = 72;
    # code that ends in a comment?
    if (/\$\s*\$.*$/) {
        # move the comment above the line
        ($code, $comment) = split(/\s*\$\s*\$/, $_);
        $_ = "\$\$$comment\n";
        if (length $code > $chunk_size) {
            # chunk the code
            $_ .= join("\$\n", chunk($code, $chunk_size));
        } else {
            $_ .= "$code";
        }
    } else {
        # chunk the statement
        $_ = join("\$\n", chunk($_, $chunk_size));
    }
}

# Given a string, and a chunk size, return a
# list of strings that size or less.
sub chunk {
    my ($i, @parts, $code, $chunk_size);
    ($code, $chunk_size) = @_;
    $chunk_size--;
    for ($i=0; $i<length $code; $i+=$chunk_size) {
        push(@parts,  substr($code, $i, $chunk_size));
    }
    return @parts;
}
