# Welcome to My Ftp
***

## Task
TODO - What is the problem? And where is the challenge?

## Description
TODO - How have you solved the problem?


```
my_ftp FTP Server Project
|
|-- 1.0 Project Initialization
|   |-- 1.1 Define project scope based on provided requirements ✓
|
|-- 2.0 Core Server Development
|   |-- 2.1 Basic Server Setup✓
|   |   |-- 2.1.1 Implement command-line argument parsing for port and path ✓
|   |   |-- 2.1.2 Initialize TCP socket and understand the concept of bind(0) ✓
|   |   |-- 2.1.3 Handle socket binding to the specified port and listening ✓
|   |-- 2.2 Multi-client Handling
|   |   |-- 2.2.1 Accept incoming client connections ✓
|   |   |-- 2.2.2 Design and implement a thread pool for handling multiple clients ✓
|   |-- 2.3 FTP Command Handling
|   |   |-- 2.3.1 Develop a command parser to detect FTP commands ✓75%
|   |   |-- 2.3.2 Implement the "USER" and "PASS" commands for "Anonymous" authentication
|   |   |-- 2.3.3 Set up data transfer commands using active and passive modes
|   |-- 2.4 File and Directory Management
|   |   |-- 2.4.1 Determine the home directory for the "Anonymous" user
|   |   |-- 2.4.2 Implement file retrieval and listing commands ✓25%
|
|-- 3.0 Protocol Adherence and Enhancement
|   |-- 3.1 Study and understand the FTP protocol (RFC959) ✓
|   |-- 3.2 Implement any additional FTP commands as per protocol 
|   |-- 3.3 Ensure data transfer adheres to active and passive modes
|
|-- 4.0 Testing and Debugging
|   |-- 4.1 Unit Testing
|   |   |-- 4.1.1 Test individual FTP command handlers
|   |   |-- 4.1.2 Test thread pool functionality and multi-client handling
|   |-- 4.2 Integration and Protocol Testing
|   |   |-- 4.2.1 Test overall server functionality using FTP clients
|   |   |-- 4.2.2 Validate server behavior against the FTP protocol (RFC959)
|
|-- 5.0 Documentation and Cleanup
|   |-- 5.1 Comment the codebase for clarity
|   |-- 5.2 Write a brief README or user manual
|   |-- 5.3 Address any known issues, limitations, or potential improvements
|
|-- 6.0 Compilation and Delivery
    |-- 6.1 Compile the server for the target platform(s)
    |-- 6.2 Package the server, documentation, and any required dependencies
    |-- 6.3 Deliver or release to intended users or stakeholders
```

two-week timeframe schedule:

Days 1-2:
- Project Initialization, Environment Setup ✓
- Preliminary Research on FTP and RFC959 ✓
Days 3-5:
- Basic Server Setup (TCP socket initialization, command-line parsing) ✓
- Multi-client Handling with Thread Pool ✓
Days 6-8:
- Implement FTP Command Handling (USER, PASS, LIST, RETR, etc.) ✓50%
- Implement Active and Passive Modes
Days 9-10:
- File and Directory Management ✓25%
- Additional FTP Commands and Features ✓25%
Days 11-12:
- Thorough Testing (Unit, Integration, Protocol Adherence)
Days 13:
- Documentation, Code Cleanup, Addressing Known Issues
Day 14:
- Compilation, Packaging, and Delivery

```

                                            -------------
                                            |/---------\|
                                            ||   User  ||    --------
                                            ||Interface|<--->| User |
                                            |\----^----/|    --------
                  ----------                |     |     |
                  |/------\|  FTP Commands  |/----V----\|
                  ||Server|<---------------->|   User  ||
                  ||  PI  ||   FTP Replies  ||    PI   ||
                  |\--^---/|                |\----^----/|
                  |   |    |                |     |     |
      --------    |/--V---\|      Data      |/----V----\|    --------
      | File |<--->|Server|<---------------->|  User   |<--->| File |
      |System|    || DTP  ||   Connection   ||   DTP   ||    |System|
      --------    |\------/|                |\---------/|    --------
                  ----------                -------------

                  Server-FTP                   USER-FTP
```

## Installation
TODO - How to install your project? npm install? make? make re?

## Usage
TODO - How does it work?
```
./my_project argument1 argument2
```

### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
