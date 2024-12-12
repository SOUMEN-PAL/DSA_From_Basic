from gtts import gTTS

script_content = """
Hey everyone! You won’t believe it, but it’s been just five days since I started learning Spring Boot, 
and I’ve already built my first project!

Let me show you what I’ve been working on. It’s an Employee Management System—a fully functional REST API that allows you to manage employee data, including creating, updating, retrieving, and deleting records.

But here’s the exciting part: I didn’t stop at just the basics. I added robust error handling using @RestControllerAdvice. 
For example, when someone tries to access an employee that doesn’t exist, the API responds with a clean and informative error message, ensuring a great user experience.

I also implemented input validation using Jakarta Validation. It ensures that data like employee names, emails, and other fields meet all the necessary criteria before they even reach the backend. If something’s not right, the API returns detailed error messages like this...

These features make the API not just functional but also reliable and user-friendly. And honestly, learning Spring Boot has been such a rewarding journey! 
In just five days, I’ve learned so much about REST APIs, validation, and error handling.

If you’re thinking of exploring Spring Boot, let me tell you—it’s worth it! The learning curve is smooth, and the possibilities are endless.

What do you think of my Employee Management System? I’d love to hear your feedback in the comments! 
And if you’re on a similar journey, feel free to share your experiences.

Let’s keep learning and building amazing things together. Thanks for watching!
"""

tts = gTTS(script_content, lang='en', slow=False)
tts.save("Employee_Management_System.mp3")
print("MP3 file created as 'Employee_Management_System.mp3'")
