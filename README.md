# A Real World Application using Neo4j

## (For CSC5425 - "Advanced Database Systems")

### Assignment 4

~~This is my submission for [Assignment 4 -Neo4J assignment](https://csc.mc.edu/moodle/mod/assign/view.php?id=12753)~~ Read the update in the next paragraph. The development OS was Linux Mint 20.3 (x86_64), Cinnamon version, running Kernel version 5.4.0.

To run it, you must first install neo4j; I installed it from a tarball following the instructions here: <https://neo4j.com/docs/operations-manual/current/installation/linux/tarball/>. After starting the neo4j daemon using the `sudo /opt/neo4j/bin/neo4j start` command (assuming you did, indeed, install from a tarball), opening the web GUI, and changing the default password, run `install_RW_proj.pl`.

**Update:**

I have been unable to get the C driver working with Neo4j; apparently, the *libneo4j-client* library only works with a deprecated protocol available in ver. 3.5 or lower, according to these links:

 + <https://github.com/cleishm/libneo4j-client/issues/49>
 + <https://stackoverflow.com/questions/60545959/libneo4j-client-cant-connect-cant-diagnose>

Rather than downgrade the neo4j database, I'll just do the other part of Assignment 4 (create a DB w/ 2 kinds of nodes, insert about 10 nodes, define 2 traversals, etc...).