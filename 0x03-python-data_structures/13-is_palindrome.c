#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 * @head: Pointer to a pointer to the first node.
 * Return: Pointer to the new first node.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL, *current = *head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return (*head);
}

/**
 * is_palindrome - Checks if a linked list is a palindrome.
 * @head: Pointer to the head of the linked list.
 * Return: 1 if the linked list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *mid = NULL, *second_half = NULL;
    listint_t *prev_of_slow = *head, *prev_of_mid = *head;
    int res = 1;

    if (*head != NULL && (*head)->next != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            prev_of_slow = slow;
            slow = slow->next;
        }

        // If fast is not NULL, the list has odd number of elements
        // Set mid to the next of slow and move slow one step further
        if (fast != NULL)
        {
            mid = slow;
            slow = slow->next;
        }

        // Reverse the second half and assign it to second_half
        second_half = slow;
        prev_of_slow->next = NULL;
        reverse_listint(&second_half);

        // Compare the first half and second half
        while (second_half != NULL)
        {
            if ((*head)->n != second_half->n)
            {
                res = 0;
                break;
            }
            *head = (*head)->next;
            second_half = second_half->next;
        }

        // Restore the original linked list
        reverse_listint(&prev_of_mid);
        if (mid != NULL)
        {
            prev_of_slow->next = mid;
            mid->next = second_half;
        }
        else
        {
            prev_of_slow->next = second_half;
        }
    }

    return res;
}

