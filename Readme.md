# 📡 minitalk

> A small client-server communication program written in **C**, using UNIX signals to transmit data between processes.

**minitalk** is a project from the **42 School** Common Core. The goal is to create a communication system where a client sends a message to a server using only UNIX signals.

The project explores **processes, signals, bit manipulation, synchronization, and inter-process communication (IPC)**.

---

## 🧠 About the Project

The project consists of two programs:

* **Server** — waits for incoming signals and reconstructs the message.
* **Client** — converts the message into bits and sends them to the server.

The communication is performed using:

```text
SIGUSR1
SIGUSR2
```

Each signal represents a binary value:

```text
SIGUSR1 → 0
SIGUSR2 → 1
```

For example, a character such as `A`:

```text
A = 01000001
```

can be transmitted bit by bit to the server.

---

## 🔄 How It Works

The basic communication flow is:

```text
                 ┌──────────────┐
                 │    CLIENT    │
                 └──────┬───────┘
                        │
                        │ SIGUSR1 / SIGUSR2
                        ▼
                 ┌──────────────┐
                 │    SERVER    │
                 └──────┬───────┘
                        │
                        ▼
                  Reconstruct
                   the message
```

The client:

1. Receives the server PID.
2. Reads the message from the command line.
3. Converts each character into binary.
4. Sends each bit using `SIGUSR1` or `SIGUSR2`.

The server:

1. Displays its PID.
2. Waits for incoming signals.
3. Receives each bit.
4. Reconstructs the bytes.
5. Prints the original message.

---

## 🛠️ Technologies

* **C**
* **UNIX Signals**
* **Processes**
* **Bit Manipulation**
* **Inter-Process Communication (IPC)**
* **Makefile**
* **Linux**
* **Git / GitHub**

---

## 📡 Signals

The project uses two user-defined UNIX signals:

| Signal    | Binary value |
| --------- | -----------: |
| `SIGUSR1` |          `0` |
| `SIGUSR2` |          `1` |

For example:

```text
Character: A

Binary:
01000001

Transmission:
SIGUSR1
SIGUSR2
SIGUSR1
SIGUSR1
SIGUSR1
SIGUSR1
SIGUSR1
SIGUSR2
```

---

## ⚙️ Compilation

Clone the repository:

```bash
git@github.com:ArilsonDjalma26/minitalk.git
cd minitalk
```

Compile both programs:

```bash
make
```

This generates:

```text
server
client
```

---

## ▶️ Usage

### 1. Start the server

```bash
./server
```

The server will display its PID:

```text
Server PID: 12345
```

### 2. Send a message

Open another terminal and run:

```bash
./client 12345 "Hello from minitalk!"
```

The server receives and displays:

```text
Hello from minitalk!
```

---

## 🔁 Example

### Terminal 1 — Server

```bash
$ ./server
Server PID: 12345
Hello from minitalk!
```

### Terminal 2 — Client

```bash
$ ./client 12345 "Hello from minitalk!"
```

---

## 🧩 Core Concepts

### Bit Manipulation

Each character is represented as a sequence of bits.

For example:

```text
'A' → 01000001
```

The client processes each bit and sends the corresponding signal.

---

### Signal Handling

The server uses signal handlers to receive:

```c
SIGUSR1
SIGUSR2
```

The signal handler reconstructs the incoming byte one bit at a time.

---

### Process Identification

The client needs the **PID (Process ID)** of the server to know where to send the signals.

```text
Client
   │
   │ PID = 12345
   ▼
Server
```

---

### Synchronization

Because signals are asynchronous, the client and server need a reliable way to synchronize their communication.

The bonus implementation can use an **acknowledgement mechanism**, allowing the server to confirm that each bit has been successfully received before the client continues.

```text
CLIENT                         SERVER

   │                              │
   │──── SIGUSR1 / SIGUSR2 ──────>│
   │                              │
   │<──────── ACK ────────────────│
   │                              │
   │──── next bit ───────────────>│
   │                              │
```

---

## 🏗️ Architecture

```text
                 MINITALK

        ┌─────────────────────┐
        │       CLIENT        │
        │                     │
        │  Message            │
        │      ↓              │
        │  Convert to bits    │
        │      ↓              │
        │  Send signals       │
        └─────────┬───────────┘
                  │
                  │
          SIGUSR1 / SIGUSR2
                  │
                  ▼
        ┌─────────────────────┐
        │       SERVER        │
        │                     │
        │  Receive signals    │
        │      ↓              │
        │  Rebuild bits       │
        │      ↓              │
        │  Rebuild character  │
        │      ↓              │
        │  Print message      │
        └─────────────────────┘
```

---

## 📁 Project Structure

```text
minitalk/
│
├── Makefile
├── README.md
│
├── includes/
│   └── minitalk.h
│
├── src/
│   ├── client.c
│   ├── server.c
│   ├── client_utils.c
│   ├── server_utils.c
│   └── ...
│
└── libft/
    └── ...
```

> The exact structure may vary depending on the implementation.

---

## 🧪 Testing

Some useful tests:

### Simple message

```bash
./client <PID> "Hello"
```

### Empty message

```bash
./client <PID> ""
```

### Numbers

```bash
./client <PID> "123456789"
```

### Special characters

```bash
./client <PID> "Hello! @#$% & *"
```

### Long message

```bash
./client <PID> "A very long message to test the communication between the client and the server."
```

---

## 🐛 Error Handling

The programs should properly handle invalid input such as:

* Invalid PID.
* Missing arguments.
* Invalid arguments.
* Incorrect number of arguments.
* Communication errors.

The goal is to ensure that the program behaves safely and does not crash unexpectedly.

---

## 🚀 What I Learned

Through **minitalk**, I developed a better understanding of:

* UNIX processes.
* Process IDs (PID).
* Signal handling.
* `SIGUSR1` and `SIGUSR2`.
* Bitwise operations.
* Binary representation.
* Inter-process communication.
* Asynchronous events.
* Signal synchronization.
* `sigaction`.
* `volatile sig_atomic_t`.
* Memory management.
* Debugging and error handling.

---

## 🎓 42 School

This project is part of the **42 School** Common Core and focuses on understanding low-level communication between processes using UNIX signals.

Rather than relying on sockets, pipes, or other high-level IPC mechanisms, `minitalk` requires building a communication protocol using signals.

---

## 👨‍💻 Author

**Arilson Albano**

42 Luanda — Student Developer

---

⭐ Feel free to explore the source code and follow my progress through the 42 Common Core.
