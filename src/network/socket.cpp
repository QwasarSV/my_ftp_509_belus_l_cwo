#include <my_main_server.hpp>

// std::string Socket::ReceiveMessage()
// {
//     char buffer[RW_SIZE];
//     std::string answer;
//     size_t byteRead = 0;
//     while ((byteRead = read(socketFd, buffer, RW_SIZE)))
//     {
//         answer.append(buffer, byteRead);
//     }
//     return answer;
// }

// void Socket::writeMessage(const std::string& message)
// {
//     ssize_t byteSent = send(socketFd, message.c_str(), message.length(), 0);
//     if (byteSent == -1)
//     {
//          // error big bad ? 
//     }
// }

// int Socket::getSocket() const
// {
//     return socketFd;
// }

