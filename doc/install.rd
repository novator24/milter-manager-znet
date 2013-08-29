# -*- rd -*-

= Install --- How to install milter manager

== About this document

This document describes how to install milter manager.

== Dependencies

This section describes softwares that are depended on
milter manager.

=== Required

milter manager depends on the following softwares. They
should be installed before building milter manager.

  * GLib >= 2.12.3
  * Ruby >= 1.8.5 (Support 1.9.x since milter manager 1.8.4)
  * Ruby/GLib2 (Ruby-GNOME2) >= 0.16.0

=== Optional: Testing

To run milter manager's unit tests, the following softwares
are needed. They are needed for running unit tests but not
needed for running milter manager.

  * Cutter >= 1.0.6
  * LCOV

=== Optional: Graph

milter manager provides a feature that generates graphs for
milter's status and so on from milter manager log. The
following softwares are required to generate graphs but they
are not required for running milter manager.

 * RRDtool
 * RRDtool's Ruby bindings

The following software is also needed to integrate with
((<Munin|URL:http://munin-monitoring.org/>)):

  * munin-node

== milter-manager

milter-manager is a core program of the milter manager
package. milter-manager works as a milter and connects to
MTA and child miltres.

Here are documents about how to install milter-manager to
your platform:

  * ((<Debian|install-to-debian.rd>))
  * ((<Ubuntu|install-to-ubuntu.rd>))
  * ((<CentOS|install-to-centos.rd>))
  * ((<FreeBSD|install-to-freebsd.rd>))
  * ((<Etc|install-to-others.rd>))

== milter-manager-log-analyzer

((<graphs generated by milter-manager-log-analyzer|milter-manager-log-analyzer-graphs.svg>))

milter-manager-log-analyzer is a program that generates
graphs from milter-manager's log. Installing
milter-manager-log-analyzer is optional.

To confirm milter behavior, we can use
milter-manager-log-analyzer. It's convenient for confirming
new milter's effect and milter result in chronological order
visually.

milter-manager-log-analyzer analyzes milter-manager logs
from syslog output. It uses
((<RRDtool|URL:http://oss.oetiker.ch/rrdtool/>)) to generate
graphs. milter-manager-log-analyzer analyzes the logs
periodically by cron.

Here are documents about how to install
milter-manager-log-analyzer.

  * ((<Debian|install-options-to-debian.rd>))
  * ((<Ubuntu|install-options-to-ubuntu.rd>))
  * ((<CentOS|install-options-to-centos.rd>))
  * ((<FreeBSD|install-options-to-freebsd.rd>))
