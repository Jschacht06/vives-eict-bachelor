# Programming Languages

Search the Internet for 5 programming languages that you never heard of before. Try to find a small code example of each. Determine if the language is compiled or interpreted.

## Solution

# Perl
# Small piece of code to create a directory
if ($#ARGV != 2) {
    print "usage: mkdirs base start stop\n";
    exit;
}

$base = $ARGV[0];
$start = $ARGV[1];
$stop = $ARGV[2];

for ($i=$start; $i <= $stop; $i++) {

    $num = $i;
    if($i<10) {	$num = "00$i"; }
    elsif($i<100) { $num = "0$i"; }

    $cmd = "mkdir $base$num";
    print $cmd."\n";
    if(system($cmd)) { print "mkdir failed\n"; }
}
# This is an interpreted language


# Rust
# Example code of Hello World
// This is the main function.
fn main() {
    println!("Hello World!");
}
# Rust in an ahead-of-time compiled language wich means you can compile it and someone else can run the exexcutable without having rust installed


# Kotlin
# Example code showing how to multiply 2 floating point numbers
fun main(args: Array<String>) {

    val first = 1.5f
    val second = 2.0f

    val product = first * second

    println("The product is: $product")
}
# This is an compiled language


# Go
# Example piece of code to print Hello World
package main

import "fmt"

func main() {
    fmt.Println("hello world")
}
# This is an compiled language


# Scala
# This is an example to print "Hello Scala"
object ScalaExample{  
    def main(args:Array[String]){  
        println "Hello Scala"  
    }  
}  
# Scala is a compiled language