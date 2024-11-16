# Dive Into Systems <br/>

## 0. [Introduction](https://diveintosystems.org/book/introduction.html)<br/>
## 1. By the C, the Beautiful C <br/>
    1.1. [Getting Started Programming in C]((https://diveintosystems.org/book/introduction.html)
    1.2. Input/Output (printf and scanf) 
    1.3. Conditionals and Loops
    1.4. Functions
    1.5. Arrays and Strings
    1.6. Structs<br/>
    1.7. Summary<br/>
    1.8. Exercises<br/>
## 2. A Deeper Dive Into C<br/>
    2.1. Parts of Program Memory and Scope<br/>
    2.2. C Pointer Variables<br/>
    2.3. Pointers and Functions<br/>
    2.4. Dynamic Memory Allocation<br/>
    2.5. Arrays in C<br/>
    2.6. Strings and the String Library<br/>
    2.7. Structs<br/>
    2.8. Input / Output in C<br/>
    2.9. Advanced C Features<br/>
      2.9.1. Constants, switch, enum, and typedef<br/>
      2.9.2. Command Line Arguments<br/>
      2.9.3. The void* Type<br/>
      2.9.4. Pointer Arithmetic<br/>
      2.9.5. C Libraries: Using, Compiling and Linking<br/>
      2.9.6. Writing and using your own C libraries (and compiling multiple .c and .h files)<br/>
      2.9.7. Compiling C to Assembly and Compiling Assembly Code<br/>
    2.10. Summary<br/>
    2.11. Exercises<br/>
## 3. C Debugging Tools<br/>
    3.1. Debugging with GDB<br/>
    3.2. GDB Commands in Detail<br/>
    3.3. Debugging Memory with Valgrind<br/>
    3.4. Advanced GDB Features<br/>
    3.5. Debugging Assembly Code<br/>
    3.6. Debugging Multi-threaded Programs<br/>
    3.7. Summary<br/>
## 4. Binary and Data Representation<br/>
    4.1. Number Bases and Unsigned Integers<br/>
    4.2. Converting Between Bases<br/>
    4.3. Signed Binary Integers<br/>
    4.4. Binary Integer Arithmetic<br/>
    4.5. Overflow<br/>
    4.6. Bitwise Operators<br/>
    4.7. Integer Byte Order<br/>
    4.8. Real Numbers in Binary<br/>
    4.9. Summary<br/>
    4.10. Exercises<br/>
## 5. What von Neumann Knew: Computer Architecture<br/>
    5.1. The Origins of Modern Computing<br/>
    5.2. The von Neumann Architecture<br/>
    5.3. Logic Gates<br/>
    5.4. Circuits<br/>
    5.4.1. Arithmetic and Logic Circuits<br/>
    5.4.2. Control Circuits<br/>
    5.4.3. Storage Circuits<br/>
    5.5. Building a Processor<br/>
    5.6. The Processor’s Execution of Program Instructions<br/>
    5.7. Pipelining Instruction Execution<br/>
    5.8. Advanced Pipelining Considerations<br/>
    5.9. Looking Ahead: CPUs Today<br/>
    5.10. Summary<br/>
    5.11. Exercises<br/>
## 6. Under the C: Dive into Assembly<br/>
    7. 64-bit x86 Assembly<br/>
    7.1. Assembly Basics<br/>
    7.2. Common Instructions<br/>
    7.3. Additional Arithmetic Instructions<br/>
    7.4. Conditional Control and Loops<br/>
    7.4.1. Preliminaries<br/>
    7.4.2. If Statements<br/>
    7.4.3. Loops<br/>
    7.5. Functions in Assembly<br/>
    7.6. Recursion<br/>
    7.7. Arrays in Assembly<br/>
    7.8. Matrices in Assembly<br/>
    7.9. Structs in Assembly<br/>
    7.10. Buffer Overflows<br/>
## 8. 32-bit x86 Assembly<br/>
    8.1. Assembly Basics<br/>
    8.2. Common Instructions<br/>
    8.3. Additional Arithmetic Instructions<br/>
    8.4. Conditional Control and Loops<br/>
    8.4.1. Preliminaries<br/>
    8.4.2. If Statements<br/>
    8.4.3. Loops<br/>
    8.5. Functions in Assembly<br/>
    8.6. Recursion<br/>
    8.7. Arrays in Assembly<br/>
    8.8. Matrices in Assembly<br/>
    8.9. Structs in Assembly<br/>
    8.10. Buffer Overflows<br/>
## 9. ARMv8 Assembly<br/>
    9.1. Assembly Basics<br/>
    9.2. Common Instructions<br/>
    9.3. Arithmetic Instructions<br/>
    9.4. Conditional Control and Loops<br/>
      9.4.1. Preliminaries<br/>
      9.4.2. If Statements<br/>
      9.4.3. Loops<br/>
    9.5. Functions in Assembly<br/>
    9.6. Recursion<br/>
    9.7. Arrays in Assembly<br/>
    9.8. Matrices in Assembly<br/>
    9.9. Structs in Assembly<br/>
    9.10. Buffer Overflows<br/>
## 10. Key Assembly Takeaways<br/>
## 11. Storage and the Memory Hierarchy<br/>
    11.1. The Memory Hierarchy<br/>
    11.2. Storage Devices<br/>
    11.3. Locality<br/>
    11.4. Caching<br/>
    11.5. Cache Analysis and Cachegrind<br/>
    11.6. Looking Ahead: Caching on Multicore Processors<br/>
    11.7. Summary<br/>
    11.8. Exercises<br/>
## 12. Code Optimization<br/>
    12.1. First Steps<br/>
    12.2. Other Compiler Optimizations<br/>
    12.3. Memory Considerations<br/>
    12.4. Summary<br/>
## 13. The Operating System<br/>
    13.1. Booting and Running<br/>
    13.2. Processes<br/>
    13.3. Virtual Memory<br/>
    13.4. Interprocess Communication<br/>
      13.4.1. Signals<br/>
      13.4.2. Message Passing<br/>
      13.4.3. Shared Memory<br/>
    13.5. Summary and Other OS Functionality<br/>
    13.6. Exercises<br/>
## 14. Leveraging Shared Memory in the Multicore Era<br/>
    14.1. Programming Multicore Systems<br/>
    14.2. POSIX Threads<br/>
    14.3. Synchronizing Threads<br/>
      14.3.1. Mutual Exclusion<br/>
      14.3.2. Semaphores<br/>
      14.3.3. Other Synchronization Constructs<br/>
    14.4. Measuring Parallel Performance<br/>
      14.4.1. Parallel Performance Basics<br/>
      14.4.2. Advanced Topics<br/>
    14.5. Cache Coherence<br/>
    14.6. Thread Safety<br/>
    14.7. Implicit Threading with OpenMP<br/>
    14.8. Summary<br/>
    14.9. Exercises<br/>
## 15. Looking Ahead: Other Parallel Systems<br/>
    15.1. Hardware Acceleration and CUDA<br/>
    15.2. Distributed Memory Systems<br/>
    15.3. To Exascale and Beyond<br/>
## 16. Appendix 1: Chapter 1 for Java Programmers<br/>
## 17. Appendix 2: Using Unix<br/>
    17.1. Unix Command Line and the Unix File System<br/>
    17.2. Man and the Unix Manual<br/>
    17.3. Remote Access<br/>
    17.4. Unix Editors<br/>
    17.5. make and Makefiles<br/>
    17.6 Searching: grep and find<br/>
    17.7 File Permissions<br/>
    17.8 Archiving and Compressing Files<br/>
    17.9 Process Control<br/>
    17.10 Timing<br/>
    17.11 Command History<br/>
    17.12 I/0 Redirection<br/>
    17.13 Pipes<br/>
    17.14 Dot Files and .bashrc<br/>
    17.15 Shell Programming<br/>
    17.16 Getting System Information<br/>
