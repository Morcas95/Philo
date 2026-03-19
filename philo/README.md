*This project has been created as part of the 42 curriculum by maalonso.*

# Philosophers

## Description

Philosophers is a 42 school project that introduces the fundamentals of concurrent programming through the classic **Dining Philosophers Problem**, originally formulated by Edsger Dijkstra in 1965.

One or more philosophers sit around a round table with a large bowl of spaghetti in the center. Each philosopher alternates between three states: **eating**, **thinking**, and **sleeping**. There is one fork between each pair of adjacent philosophers, and a philosopher needs both the fork to their left and the fork to their right in order to eat.

The goal is to simulate this scenario without any philosopher dying of starvation, and without any data races.

The mandatory part implements the simulation using **POSIX threads** (`pthreads`) and **mutexes** to protect shared resources.

## Instructions

### Compilation

Clone the repository and navigate to the project directory.

**Mandatory part:**
```bash
cd philo
make
```

To clean object files:
```bash
make clean
```

To remove all build artifacts:
```bash
make fclean
```

To recompile from scratch:
```bash
make re
```

### Usage

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument | Description |
|---|---|
| `number_of_philosophers` | Number of philosophers (and forks) at the table |
| `time_to_die` (ms) | Time before a philosopher dies if they haven't started eating |
| `time_to_eat` (ms) | Time it takes a philosopher to eat |
| `time_to_sleep` (ms) | Time a philosopher spends sleeping |
| `number_of_times_each_philosopher_must_eat` | *(Optional)* Simulation stops when all philosophers have eaten this many times |

### Examples

```bash
# 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Same, but stop after each philosopher eats 7 times
./philo 5 800 200 200 7

# Edge case: single philosopher (will always die)
./philo 1 800 200 200
```

### Log Format

Every state change is printed in the following format:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

## Resources

### Classic References

- [Dining Philosophers Problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads Programming — Lawrence Livermore National Laboratory](https://hpc-tutorials.llnl.gov/posix/)
- [pthread_mutex — Linux man page](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [gettimeofday — Linux man page](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)

### AI Usage

AI tools (Claude) were used during this project in the following ways:

- **Documentation**: Assisted in generating this README structure and wording.
- **Concept clarification**: Used to better understand mutex locking order and deadlock avoidance strategies.
- **Debugging guidance**: Helped identify potential data race conditions and suggested how to reason about thread safety.

