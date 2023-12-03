#include "Application.h"

Application::Application()
{
	angle = 0;
}

Application::~Application()
{
}

void Application::setupPerspective()
{
	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 1000.0f);
	shader->setMat4("projection", projection);
}

void Application::setupCamera()
{
	// LookAt camera (position, target/direction, up)
	viewPos = glm::vec3(5, 1, 5);
	glm::mat4 view = glm::lookAt(viewPos, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	shader->setMat4("view", view);
}

void Application::setupLighting()
{
	// set lighting attributes
	glm::vec3 lightPos = glm::vec3(4, 4, 0);
	shader->setVec3("lightPos", lightPos);
	shader->setVec3("viewPos", viewPos);
	glm::vec3 lightColor = glm::vec3(0.8f, 0.8f, 0.8f);
	shader->setVec3("lightColor", lightColor);
}

void Application::Init()
{
	// Build a lighting map shader
	shader = new Shader("cube.vert", "cube.frag");
	shader->Init();
	// Create instance of cube
	cube = new Cube(shader);
	cube->Init();
	cube->SetRotation(0, 0, 1, 0);

	// setup perspective 
	setupPerspective();
	// setup camera
	setupCamera();
	// setup lighting
	setupLighting();
}

void Application::DeInit()
{
	delete cube;
}

void Application::Update(double deltaTime)
{
	lastLightToggled += deltaTime;
	angle += (float)((deltaTime * 0.5f) / 1000);
	ProcessInput(this->window);
}

void Application::Render()
{
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SetBackgroundColor(94, 232, 247);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);

	// Desk 1 (wider)
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(-2.0, -0.25, 0.0);  // Adjusted position for Desk 1
	cube->SetScale(3.0, 0.3, 0.9);
	cube->Draw();

	// Legs of Desk 1 (connecting at each corner)
	// Bottom-left corner
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(-3.45, -0.65, -0.35);
	cube->SetScale(0.1, 0.7, 0.1);
	cube->Draw();

	// Bottom-right corner
	cube->SetPosition(-0.55, -0.65, -0.35);
	cube->Draw();

	// Top-left corner
	cube->SetPosition(-3.45, -0.65, 0.35);
	cube->Draw();

	// Top-right corner
	cube->SetPosition(-0.55, -0.65, 0.35);
	cube->Draw();

	// Monitors on the desk (separated, same width, slightly forward, taller, wider gap)
	// Left monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(-3.15, 0.1, 0.1);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Mid Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(-2.0, 0.1, 0.1);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Right Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(-0.85, 0.1, 0.1);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	// Desk 2 (wider) with a gap
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(2.0, -0.25, 0.0);  // Adjusted position for Desk 2
	cube->SetScale(3.0, 0.3, 0.9);
	cube->Draw();

	// Legs of Desk 2 (connecting at each corner)
	// Bottom-left corner
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(0.55, -0.65, -0.35);
	cube->SetScale(0.1, 0.7, 0.1);
	cube->Draw();

	// Bottom-right corner
	cube->SetPosition(3.45, -0.65, -0.35);
	cube->Draw();

	// Top-left corner
	cube->SetPosition(0.55, -0.65, 0.35);
	cube->Draw();

	// Top-right corner
	cube->SetPosition(3.45, -0.65, 0.35);
	cube->Draw();

	// Left monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(0.85, 0.1, 0.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Mid Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(2.0, 0.1, 0.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Right Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(3.15, 0.1, 0.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	// Desk 3 (wider)
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(-2.0, -0.25, 3.0);  // Adjusted position for Desk 3
	cube->SetScale(3.0, 0.3, 0.9);
	cube->Draw();

	// Legs of Desk 3 (connecting at each corner)
	// Bottom-left corner
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(-3.45, -0.65, 2.65);
	cube->SetScale(0.1, 0.7, 0.1);
	cube->Draw();

	// Bottom-right corner
	cube->SetPosition(-0.55, -0.65, 2.65);
	cube->Draw();

	// Top-left corner
	cube->SetPosition(-3.45, -0.65, 3.35);
	cube->Draw();

	// Top-right corner
	cube->SetPosition(-0.55, -0.65, 3.35);
	cube->Draw();

	// Monitors on the desk (separated, same width, slightly forward, taller, wider gap)
	// Left monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(-3.15, 0.1, 3.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Mid Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(-2.0, 0.1, 3.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Right Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(-0.85, 0.1, 3.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	// Desk 4 (wider)
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(-2.0, -0.25, 6.0);  // Adjusted position for Desk 4
	cube->SetScale(3.0, 0.3, 0.9);
	cube->Draw();

	// Legs of Desk 4 (connecting at each corner)
	// Bottom-left corner
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(-3.45, -0.65, 5.65);
	cube->SetScale(0.1, 0.7, 0.1);
	cube->Draw();

	// Bottom-right corner
	cube->SetPosition(-0.55, -0.65, 5.65);
	cube->Draw();

	// Top-left corner
	cube->SetPosition(-3.45, -0.65, 6.35);
	cube->Draw();

	// Top-right corner
	cube->SetPosition(-0.55, -0.65, 6.35);
	cube->Draw();

	// Monitors on the desk (separated, same width, slightly forward, taller, wider gap)
	// Left monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(-3.15, 0.1, 6.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Mid Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(-2.0, 0.1, 6.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Right Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(-0.85, 0.1, 6.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	// Desk 5 (wider) with a gap
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(2.0, -0.25, 3.0);  // Adjusted position for Desk 5
	cube->SetScale(3.0, 0.3, 0.9);
	cube->Draw();

	// Legs of Desk 5 (connecting at each corner)
	// Bottom-left corner
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(0.55, -0.65, 2.65);
	cube->SetScale(0.1, 0.7, 0.1);
	cube->Draw();

	// Bottom-right corner
	cube->SetPosition(3.45, -0.65, 2.65);
	cube->Draw();

	// Top-left corner
	cube->SetPosition(0.55, -0.65, 3.35);
	cube->Draw();

	// Top-right corner
	cube->SetPosition(3.45, -0.65, 3.35);
	cube->Draw();

	// Left monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(0.85, 0.1, 3.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Mid Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(2.0, 0.1, 3.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Right Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(3.15, 0.1, 3.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	// Desk 6 (wider) with a gap
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(2.0, -0.25, 6.0);  // Adjusted position for Desk 6
	cube->SetScale(3.0, 0.3, 0.9);
	cube->Draw();

	// Legs of Desk 6 (connecting at each corner)
	// Bottom-left corner
	cube->SetColor(120.0, 160.0, 200.0);
	cube->SetPosition(0.55, -0.65, 5.65);
	cube->SetScale(0.1, 0.7, 0.1);
	cube->Draw();

	// Bottom-right corner
	cube->SetPosition(3.45, -0.65, 5.65);
	cube->Draw();

	// Top-left corner
	cube->SetPosition(0.55, -0.65, 6.35);
	cube->Draw();

	// Top-right corner
	cube->SetPosition(3.45, -0.65, 6.35);
	cube->Draw();

	// Left monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(0.85, 0.1, 6.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Mid Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(2.0, 0.1, 6.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	//Right Monitor
	cube->SetColor(30.0, 30.0, 30.0);
	cube->SetPosition(3.15, 0.1, 6.0);
	cube->SetScale(0.5, 0.6, 0.3);
	cube->Draw();

	// Right wall
	cube->SetColor(198.0, 151.0, 116.0);
	cube->SetPosition(-4.55, 1.55, 5.0);
	cube->SetScale(0.1, 5.0, 12.5);
	cube->Draw();

	// Left wall
	cube->SetColor(198.0, 151.0, 116.0);
	cube->SetPosition(5.35, 1.55, 5.0);
	cube->SetScale(0.1, 5.0, 12.5);
	cube->Draw();

	// Door on the left wall
	cube->SetColor(255.0, 255.0, 255.0);  // Brown color for the door
	cube->SetPosition(5.3, 0.8, 9.0);  // Adjust the position of the door
	cube->SetScale(0.1, 3.5, 2.0);  // Adjust the size of the door
	cube->Draw();

	// Front wall
	cube->SetColor(99.0, 126.0, 118.0);
	cube->SetPosition(0.4, 1.55, 11.2);
	cube->SetScale(10.0, 5.0, 0.1);
	cube->Draw();

	// TV Screen
	cube->SetColor(0.0, 0.0, 0.0);  // Black color for the screen
	cube->SetPosition(0.4, 1.5, 11.19);  // Slightly in front of the wall
	cube->SetScale(4.0, 2.5, 0.1);  // Adjust the size of the screen
	cube->Draw();

	// TV Stand
	cube->SetColor(150.0, 150.0, 150.0);  // Gray color for the stand
	cube->SetPosition(0.4, 0.1, 11.13);  // Below the screen
	cube->SetScale(2.8, 0.5, 0.2);  // Adjust the size of the stand
	cube->Draw();

	// Back wall
	cube->SetColor(99.0, 126.0, 118.0);
	cube->SetPosition(0.4, 1.55, -1.2);
	cube->SetScale(10.0, 5.0, 0.1);
	cube->Draw();

	// Floor
	cube->SetColor(49.0, 48.0, 77.0);
	cube->SetPosition(0.4, -1.0, 5.0);
	cube->SetScale(10.0, 0.1, 12.5);
	cube->Draw();

	// Ceiling
	cube->SetColor(198.0, 151.0, 116.0);
	cube->SetPosition(0.4, 4.0, 5.0);
	cube->SetScale(10.0, 0.1, 12.5);
	cube->Draw();

	glDisable(GL_DEPTH_TEST);

}

void Application::UpdateCameraDirection(double xpos, double ypos)
{
	// Update yaw dan pitch berdasarkan input mouse
	yaw += xpos;
	pitch += ypos;

	// Batasi pitch agar tidak melebihi batas atas dan bawah
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	// Hitung vektor arah kamera berdasarkan yaw dan pitch
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	// Normalisasi vektor arah kamera
	viewDir = glm::normalize(front);

	// Perbarui matriks pandangan (view matrix)
	glm::mat4 view = glm::lookAt(viewPos, viewPos + viewDir, glm::vec3(0, 1, 0));
	shader->setMat4("view", view);
}


void Application::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	// Faktor sensitivitas mouse
	float sensitivity = 0.5f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	// Update orientasi kamera berdasarkan input mouse
	UpdateCameraDirection(xoffset, yoffset);

	// Fixed camera movement speed
	float fixedMovementSpeed = 0.01f;

	// Update camera position based on keyboard input
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		viewPos += fixedMovementSpeed * viewDir;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		viewPos -= fixedMovementSpeed * viewDir;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		viewPos -= glm::normalize(glm::cross(viewDir, glm::vec3(0.0f, 1.0f, 0.0f))) * fixedMovementSpeed;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		viewPos += glm::normalize(glm::cross(viewDir, glm::vec3(0.0f, 1.0f, 0.0f))) * fixedMovementSpeed;


	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && lastLightToggled > 200) {
		lampOn = !lampOn;
		lastLightToggled = 0;
	}

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && lastLightToggled > 200) {
		skyOn = !skyOn;
		lastLightToggled = 0;
	}
}



int main(int argc, char** argv) {
	Application app = Application();
	app.Start("Cube Example",
		1366, 768,
		false,
		false);
}