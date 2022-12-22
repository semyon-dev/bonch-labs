import email
import poplib

server = poplib.POP3_SSL('pop.gmail.com', port=995)

# ваши данные
server.user('')
server.pass_('')

# получаем список сообщений
response, messages, octets = server.list()

print(f'Количество сообщений: {len(messages)}')

for msg in messages:
    # Parse the message number and size from the message list
    msg_num, msg_size = msg.decode().split()
    msg_num = int(msg_num)

    # Get the message data
    response, msg_data, octets = server.retr(msg_num)

    # Concatenate the message data into a single string
    msg_data = b'\n'.join(msg_data)

    # Parse the message data into an email object
    msg = email.message_from_bytes(msg_data)

    # Print the subject and sender of the message
    print(f'Subject: {msg["Subject"]}')
    print(f'Sender: {msg["From"]}')

    # Check if the message has attachments
    if msg.get_content_maintype() == 'multipart':
        # Iterate over the attachments
        for part in msg.get_payload():
            # Check if the part is an attachment
            if part.get_content_disposition() == 'attachment':
                # Get the attachment filename and data
                filename = part.get_filename()
                data = part.get_payload(decode=True)

                # Save the attachment to a file
                with open(filename, 'wb') as f:
                    f.write(data)

                # Print the attachment filename
                print(f'Attachment: {filename}')

# Disconnect from the server
server.quit()
