# Philosophers
  Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger, I learned how to create threads manage them and definitely how to perfectly use mutexes to succeed this project.

# Rule
  One or several philosophers sit at a round table and perform three actions. (Eating, thinking, sleeping).
  If you are doing one action, you are not doing the rest.
  In the center of the round table is a bowl of spaghetti.
  There is a fork on the table.
  Spaghetti should be eaten with a fork in each hand.
  A philosopher must not starve.
  Every philosopher must eat.
  Philosophers do not talk to each other.
  Philosophers do not know if other philosophers die.
  After the philosopher finishes eating, he puts down his fork and goes to sleep.
  After the philosopher has finished sleeping, he begins to think.
  The simulation stops when one philosopher dies.

! Arguments are given in the following order
  Nubmer_of_philosophers : number of philosophers, number of forks.
  Time_to_die : in milliseconds, die time_to_die milliseconds since the last meal or start of the simulation.
  Time_to_eat : In milliseconds, how long it takes the philosopher to eat. Have 2 forks with you during this time.
  Time_to_sleep : in milliseconds, how long it takes the philosopher to sleep.
  Number_of_times_each_philosopher_must_eat: Optional, if all philosophers have eaten at least number_of_times_each_philosopher_muset_eat, the simulation ends.

! Each philosopher is given a number from 1 to number_of_philosophers
  Philosopher N sits between N - 1 and N + 1. Philosopher 1 is next to number_of_philosophers.

! What the philosopher does is output as: (X is the philosopher number)
  Timestamp_in_ms X has taken a fork.
  Timestamp_in_ms X is eating.
  Timestamp_in_ms X is sleeping.
  Timestamp_in_ms X is thinking.
  Timestamp_in_ms X died.

! Output sentences must not overlap or intertwine with other sentences.
! When the philosopher dies, it shouldn't take more than 10 ms to actually print out.
! A philosopher must avoid dying.
! There is one fork between the philosophers.
! To prevent the fork from being copied, the state of the fork must be protected with a mutex.
! Each philosopher must be a thread.

# Summary
  Philosophers are seated around a round table, with a fork between each philosopher.
  The philosopher eats, sleeps, and thinks.
  But when you eat, you have to eat spaghetti with two forks.
  So, when one is eating, the other cannot eat.
  Then, when one of the philosophers starves to death, the simulation ends.

# Available Functions
  memset, printf, malloc, free, write,
  usleep, gettimeofday, pthread_create,
  pthread_detach, pthread_join, pthread_mutex_init,
  pthread_mutex_destroy, pthread_mutex_lock,
  pthread_mutex_unlock.

# Ressources
- Threads : http://www.compsci.hunter.cuny.edu/~sweiss/course_materials/unix_lecture_notes/chapter_10.pdf
- Multithreading : https://beej.us/guide/bgc/html/split/multithreading.html
- Explaining {Thread, Multithreading, Mutex, Semaphore} : https://www.notion.so/Philosophers-2b872948598e4f0cba91c66d8b5ba821
- Youtube playlist that covers Threads, Mutexes and Semaphores : https://www.youtube.com/watchv=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&pp=iAQB
- Youtube playlist about threads : https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM
- Youtube Video explaining The Dining Philosophers Problem : https://www.youtube.com/watch?v=FYUi-u7UWgw
- Very simple web visualizer for Philosophers : https://nafuka11.github.io/philosophers-visualizer/
