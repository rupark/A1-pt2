//lang::Cpp

#pragma once

#include <stdio.h>
#include "object.h" // our implementation of Object for A1
#include "queue.h"  // our implementation of Queue for A1
#include "string.h" // our implementation of String from Warmup

void FAIL()
{
    printf("Failed.");
}
void OK(const char *m)
{
    printf("Passed!");
}
void t_true(bool p)
{
    if (!p)
        FAIL();
}
void t_false(bool p)
{
    if (p)
        FAIL();
}

// test enqueue
void test1()
{
    String *s = new String("Hello");
    String *t = new String("World");
    Queue *q1 = new Queue();

    t_true(q1->queue_size() == 0);
    q1->enqueue(s);
    q1->enqueue(t);
    t_true(q1->queue_size() == 2);
    OK("1");
}

//test dequeue
void test2()
{
    String *s = new String("Hello");
    String *t = new String("World");
    String *u = s->concat(t);
    Queue *q1 = new Queue();

    q1->enqueue(s);
    q1->enqueue(t);
    q1->enqueue(u);
    t_true(q1->dequeue()->equals(s));
    t_true(q1->dequeue()->equals(t));
    t_false(q1->dequeue()->equals(s));
    OK("1");
}

//test equals
void test3()
{
    String *s = new String("Hello");
    String *t = new String("World");
    String *u = s->concat(t);
    Queue *q1 = new Queue();
    Queue *q2 = new Queue();

    t_true(q1->equals(q2));
    q1->enqueue(s);
    q1->enqueue(t);
    q2->enqueue(s);
    q2->enqueue(t);
    t_true(q1->equals(q2));
    q1->enqueue(u);
    t_false(q1->equals(q2));
    OK("1");
}

//test hash_me
void test4()
{
    String *s = new String("Hello");
    String *t = new String("World");
    Queue *q1 = new Queue();
    Queue *q2 = new Queue();

    q1->enqueue(s);
    q2->enqueue(t);
    t_true(q1->hash_me() > 0);
    t_true(q1->hash_me() == q1->hash_me());
    t_false(q2->hash_me() <= 0);
    OK("1");
}

//test peek
void test5()
{
    String *s = new String("Hello");
    String *t = new String("World");
    Queue *q1 = new Queue();

    q1->enqueue(s);
    q1->enqueue(t);
    t_true(q1->peek()->equals(s));
    q1->dequeue();
    t_true(q1->peek()->equals(t));
    OK("1");
}

//test contains
void test6()
{
    String *s = new String("Hello");
    String *t = new String("World");
    Queue *q1 = new Queue();

    q1->enqueue(s);
    t_true(q1->contains(s));
    t_false(q1->contains(t));
    q1->enqueue(t);
    t_true(q1->contains(t));
    OK("1");
}

//test enqueue_all
void test7()
{
    String *s = new String("Hello");
    String *t = new String("World");
    String *u = s->concat(t);
    String *v = new String("Yay Me");
    Queue *q1 = new Queue();
    Queue *q2 = new Queue();

    t_true(q1->queue_size() == 0);
    t_true(q2->queue_size() == 0);
    q1->enqueue(s);
    q1->enqueue(t);
    q2->enqueue(u);
    q2->enqueue(v);
    t_true(q1->queue_size() == 2);
    t_true(q2->queue_size() == 2);
    q1->enqueue_all(q2);
    t_true(q1->queue_size() == 4);
    t_true(q1->contains(v));
    OK("1");
}

//test dequeue_all
void test8()
{
    String *s = new String("Hello");
    String *t = new String("World");
    Queue *q1 = new Queue();

    t_true(q1->queue_size() == 0);
    q1->enqueue(s);
    q1->enqueue(t);
    t_true(q1->queue_size() == 2);
    q1->dequeue_all();
    t_true(q1->queue_size() == 0);
    OK("1");
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    return 0;
}
