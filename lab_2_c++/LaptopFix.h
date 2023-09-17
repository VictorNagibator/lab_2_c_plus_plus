#pragma once
#include <iostream>
#include <istream>
#include <stdexcept>
#include <vector>


class CPU
{
public:
	CPU();
	CPU(std::string name);
	CPU(std::string name, float frequency, int numOfCores);
	~CPU();

	void operator=(CPU other);

	std::string GetName() const;
	float GetFrequency() const;
	int GetNumOfCores() const;
	void Input();

	const float maxFreq = 9.0; //�������� ������������ �������� ������� ��� ����������
private:
	std::string name;
	float frequency;
	int numOfCores;

	bool CheckArguments(std::string name, float frequency, int numOfCores);
};

void CPU::operator=(CPU other) {
	this->name = other.GetName();
	this->frequency = other.GetFrequency();
	this->numOfCores = other.GetNumOfCores();
}

bool CPU::CheckArguments(std::string name, float frequency, int numOfCores) {
	return frequency >= 0 && frequency < maxFreq && numOfCores >= 0;
}

CPU::CPU()
{
	frequency = numOfCores = 0; 
}

CPU::CPU(std::string name)
{
	this->name = name;
	frequency = numOfCores = 0;
}

CPU::CPU(std::string name, float frequency, int numOfCores)
{
	if (CheckArguments(name, frequency, numOfCores)) {
		this->name = name;
		this->frequency = frequency;
		this->numOfCores = numOfCores;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

CPU::~CPU()
{
}

std::string CPU::GetName() const {
	return name;
}

float CPU::GetFrequency() const {
	return frequency;
}

int CPU::GetNumOfCores() const {
	return numOfCores;
}

void CPU::Input() {
	std::string name;
	float frequency;
	int numOfCores;

	std::cout << "������� �������� ����������: ";
	std::cin >> name;
	std::cout << "������� ��� �������� ������� (� ���): ";
	std::cin >> frequency;
	std::cout << "������� ���������� ����: ";
	std::cin >> numOfCores;
	if (CheckArguments(name, frequency, numOfCores)) {
		this->name = name;
		this->frequency = frequency;
		this->numOfCores = numOfCores;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}


class GPU
{
public:
	GPU();
	GPU(std::string name);
	GPU(std::string name, float frequency, int vram);
	~GPU();

	void operator=(GPU other);

	std::string GetName() const;
	float GetFrequency() const;
	int GetVRAM() const;
	void Input();
private:
	std::string name;
	float frequency;
	int vram;

	bool CheckArguments(std::string name, float frequency, int vram);
};

void GPU::operator=(GPU other) {
	this->name = other.GetName();
	this->frequency = other.GetFrequency();
	this->vram = other.GetVRAM();
}

bool CheckArguments(std::string name, float frequency, int vram) {
	return frequency >= 0 && vram >= 0;
}

GPU::GPU()
{
	frequency = vram = 0;
}

GPU::GPU(std::string name)
{
	this->name = name;
	frequency = vram = 0;
}

GPU::GPU(std::string name, float frequency, int vram)
{
	if (CheckArguments(name, frequency, vram)) {
		this->name = name;
		this->frequency = frequency;
		this->vram = vram;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

GPU::~GPU()
{
}

std::string GPU::GetName() const  {
	return name;
}

float GPU::GetFrequency() const {
	return frequency;
}

int GPU::GetVRAM() const {
	return vram;
}

void GPU::Input() {
	std::string name;
	float frequency;
	int vram;

	std::cout << "������� �������� ����������: ";
	std::cin >> name;
	std::cout << "������� �������� ������� ������������ ���������� (� ���): ";
	std::cin >> frequency;
	std::cout << "������� ����� ����������� (� ��): ";
	std::cin >> vram;
	if (CheckArguments(name, frequency, vram)) {
		this->name = name;
		this->frequency = frequency;
		this->vram = vram;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}


enum RAMType { DDR, DDR2, DDR3, DDR4, DDR5 };

std::istream &operator >> (std::istream& in, RAMType& type) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		type = DDR;
		break;
	case 1:
		type = DDR2;
		break;
	case 2:
		type = DDR3;
		break;
	case 3:
		type = DDR4;
		break;
	case 4:
		type = DDR5;
		break;
	default:
		break;
	}
	return in;
};

std::ostream& operator << (std::ostream& out, RAMType& type) {
	switch (type)
	{
	case DDR:
		out << "DDR";
		break;
	case DDR2:
		out << "DDR2";
		break;
	case DDR3:
		out << "DDR3";
		break;
	case DDR4:
		out << "DDR4";
		break;
	case DDR5:
		out << "DDR5";
		break;
	default:
		break;
	}
	return out;
};

class RAM
{
public:
	RAM();
	RAM(std::string name);
	RAM(std::string name, RAMType type, float frequency, int capacity);
	~RAM();

	void operator=(RAM other);

	std::string GetName() const;
	RAMType GetRAMType() const;
	float GetFrequency() const;
	int GetCapacity() const;
	void Input();

	const std::vector<int> DDRFreqMax = { 400, 1066, 2400, 3333, 6400 };
private:
	std::string name;
	RAMType type;
	float frequency;
	int capacity;

	bool CheckArguments(std::string name, RAMType type, float frequency, int capacity);
};

void RAM::operator=(RAM other) {
	this->name = other.GetName();
	this->type = other.GetRAMType();
	this->frequency = other.GetFrequency();
	this->capacity = other.GetCapacity();
}

bool RAM::CheckArguments(std::string name, RAMType type, float frequency, int capacity) {
	return type >= DDR && type <= DDR5 && frequency >= 0 && capacity >= 0;
}

RAM::RAM()
{
	type = DDR;
	frequency = capacity = 0;
}

RAM::RAM(std::string name)
{
	this->name = name;
	type = DDR;
	frequency = capacity = 0;
}

RAM::RAM(std::string name, RAMType type, float frequency, int capacity)
{
	if (CheckArguments(name, type, frequency, capacity)) {
		this->name = name;
		this->frequency = frequency;
		this->capacity = capacity;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

RAM::~RAM()
{
}

std::string RAM::GetName() const {
	return name;
}

RAMType RAM::GetRAMType() const {
	return type;
}

float RAM::GetFrequency() const {
	return frequency;
}

int RAM::GetCapacity() const {
	return capacity;
}

void RAM::Input() {
	std::string name;
	RAMType type;
	float frequency;
	int capacity;

	std::cout << "������� �������� RAM: ";
	std::cin >> name;
	std::cout << "������� ��� ������ (DDR - 0, DDR2 - 1, DDR3 - 2, DDR4 - 3, DDR5 - 4): ";
	std::cin >> type;
	std::cout << "������� �������� ������� (� ���): ";
	std::cin >> frequency;
	std::cout << "������� ����� (� ��): ";
	std::cin >> capacity;
	if (CheckArguments(name, type, frequency, capacity)) {
		this->name = name;
		this->type = type;
		this->frequency = frequency;
		this->capacity = capacity;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}


class Motherboard
{
public:
	Motherboard();
	Motherboard(std::string name);
	Motherboard(std::string name, std::string socket, std::string chipset);
	~Motherboard();

	void operator=(Motherboard other);

	std::string GetName() const;
	std::string GetSocket() const;
	std::string GetChipset() const;
	void Input();
private:
	std::string name;
	std::string socket;
	std::string chipset;
};

void Motherboard::operator=(Motherboard other) {
	this->name = other.GetName();
	this->socket = other.GetSocket();
	this->chipset = other.GetChipset();
}

Motherboard::Motherboard()
{
}

Motherboard::Motherboard(std::string name)
{
	this->name = name;
}

Motherboard::Motherboard(std::string name, std::string socket, std::string chipset)
{
	this->name = name;
	this->socket = socket;
	this->chipset = chipset;
}

Motherboard::~Motherboard()
{
}

std::string Motherboard::GetName() const {
	return name;
}

std::string Motherboard::GetSocket() const {
	return socket;
}

std::string Motherboard::GetChipset() const {
	return chipset;
}

void Motherboard::Input() {
	std::string name, socket, chipset;

	std::cout << "������� �������� ����������� �����: ";
	std::cin >> name;
	std::cout << "������� �����: ";
	std::cin >> socket;
	std::cout << "������� ������: ";
	std::cin >> chipset;
	this->name = name;
	this->socket = socket;
	this->chipset = chipset;
}


class Display
{
public:
	Display();
	Display(int width, int height);
	Display(int width, int height, int refreshRate);
	~Display();

	void operator=(Display other);

	int GetWidth() const; 
	int GetHeight() const;
	int GetRefreshRate() const;
	void Input();
private:
	int width, height, refreshRate;

	bool CheckArguments(int width, int height);
	bool CheckArguments(int width, int height, int refreshRate);
};

void Display::operator=(Display other) {
	this->width = other.GetWidth();
	this->height = other.GetHeight();
	this->refreshRate = other.GetRefreshRate();
}

bool Display::CheckArguments(int width, int height) {
	return width >= 0 && height >= 0;
}

bool Display::CheckArguments(int width, int height, int refreshRate) {
	return width >= 0 && height >= 0 && refreshRate >= 0;
}

Display::Display()
{
	width = height = refreshRate = 0;
}

Display::Display(int width, int height)
{
	if (CheckArguments(width, height)) {
		this->width = width;
		this->height = height;
		refreshRate = 0;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

Display::Display(int width, int height, int refreshRate)
{
	if (CheckArguments(width, height, refreshRate)) {
		this->width = width;
		this->height = height;
		this->refreshRate = refreshRate;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

Display::~Display()
{
}

int Display::GetWidth() const {
	return width;
}

int Display::GetHeight() const {
	return height;
}

int Display::GetRefreshRate() const {
	return refreshRate;
}

void Display::Input() {
	int width, height, refreshRate;

	std::cout << "������� ������ � ������ ������ (� ��������): ";
	std::cin >> width >> height;
	std::cout << "������� ������� ���������� ������ (� ��): ";
	std::cin >> refreshRate;
	if (CheckArguments(width, height, refreshRate)) {
		this->width = width;
		this->height = height;
		this->refreshRate = refreshRate;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}


class Laptop
{
public:
	Laptop();
	Laptop(std::string name);
	Laptop(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display);
	~Laptop();

	void operator=(Laptop other);

	std::string GetName() const;
	CPU GetCPU() const;
	GPU GetGPU() const;
	RAM GetRAM() const;
	Motherboard GetMotherboard() const;
	Display GetDisplay() const;
	void Input();
	void BoostCPU();
	void BoostRAM();
	void Print() const;
private:
	std::string name;
	CPU cpu;
	GPU gpu;
	RAM ram;
	Motherboard motherboard;
	Display display;
};

void Laptop::operator=(Laptop other) {
	this->name = other.GetName();
	this->cpu = other.GetCPU();
	this->gpu = other.GetGPU();
	this->motherboard = other.GetMotherboard();
	this->ram = other.GetRAM();
	this->display = other.GetDisplay();
}

Laptop::Laptop()
{
	cpu = CPU();
	gpu = GPU();
	ram = RAM();
	motherboard = Motherboard();
	display = Display();
}

Laptop::Laptop(std::string name) {
	this->name = name;
	cpu = CPU();
	gpu = GPU();
	ram = RAM();
	motherboard = Motherboard();
	display = Display();
}

Laptop::Laptop(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display) {
	this->name = name;
	this->cpu = cpu;
	this->gpu = gpu;
	this->ram = ram;
	this->motherboard = motherboard;
	this->display = display;
}

Laptop::~Laptop()
{
}

std::string Laptop::GetName() const {
	return name;
}

CPU Laptop::GetCPU() const {
	return cpu;
}

GPU Laptop::GetGPU() const  {
	return gpu;
}

RAM Laptop::GetRAM() const  {
	return ram;
}

Motherboard Laptop::GetMotherboard() const  {
	return motherboard;
}

Display Laptop::GetDisplay() const  {
	return display;
}

void Laptop::Input() {
	std::cout << "������� �������� ��������: ";
	std::cin >> name;
	std::cout << "\t���� ���������� ����������\n";
	cpu.Input();
	std::cout << "\t���� ���������� ����������\n";
	gpu.Input();
	std::cout << "\t���� ���������� RAM\n";
	ram.Input();
	std::cout << "\t���� ���������� ����������� �����\n";
	motherboard.Input();
	std::cout << "\t���� ���������� ������\n";
	display.Input();
}

void Laptop::BoostCPU() {
	if (this->cpu.GetFrequency() + 0.2 <= this->cpu.maxFreq) {
		cpu = CPU(this->cpu.GetName(), this->cpu.GetFrequency() + 0.2, this->cpu.GetNumOfCores());
	}
	else if (this->cpu.GetFrequency() < this->cpu.maxFreq) {
		cpu = CPU(this->cpu.GetName(), this->cpu.maxFreq, this->cpu.GetNumOfCores());
	}
	else std::cout << "������ CPU ������ ����������!\n";
}

void Laptop::BoostRAM() {
	if (this->ram.GetFrequency() + 50 <= this->ram.DDRFreqMax[this->ram.GetRAMType()]) {
		ram = RAM(this->ram.GetName(), this->ram.GetRAMType(), this->ram.GetFrequency() + 50, this->ram.GetCapacity());
	}
	else if (this->ram.GetFrequency() < this->ram.DDRFreqMax[this->ram.GetRAMType()]) {
		ram = RAM(this->ram.GetName(), this->ram.GetRAMType(), this->ram.DDRFreqMax[this->ram.GetRAMType()], this->ram.GetCapacity());
	}
	else std::cout << "������ RAM ������ ����������!\n";
}

void Laptop::Print() const {
	RAMType tempRAMType = this->ram.GetRAMType();
	std::cout << "\t���������� � ��������\n";
	std::cout << "�������� ������: " << this->name << "\n";
	std::cout << "CPU: " << this->cpu.GetName() << ", " << this->cpu.GetFrequency() << " ���, " << this->cpu.GetNumOfCores() << "-�������\n";
	std::cout << "GPU: " << this->gpu.GetName() << ", " << this->gpu.GetFrequency() << " ���, " << this->gpu.GetVRAM() << " ��\n";
	std::cout << "RAM: " << this->ram.GetName() << ", " << tempRAMType << ", " << this->ram.GetCapacity() << " ��, " << this->ram.GetFrequency() << " ���\n";
	std::cout << "����������� �����: " << this->motherboard.GetName() << ", " << this->motherboard.GetSocket() << ", " << this->motherboard.GetChipset() << "\n";
	std::cout << "�����: " << this->display.GetWidth() << "x" << this->display.GetHeight() << ", "  << this->display.GetRefreshRate() << " ��\n\n";
}


enum StatusType { ONHOLD, INPROCCESS, FINISHED };

std::istream& operator >> (std::istream& in, StatusType& status) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		status = ONHOLD;
		break;
	case 1:
		status = INPROCCESS;
		break;
	case 2:
		status = FINISHED;
		break;
	default:
		break;
	}
	return in;
};

std::ostream& operator << (std::ostream& out, StatusType& status) {
	switch (status)
	{
	case ONHOLD:
		out << "� ��������";
		break;
	case INPROCCESS:
		out << "� �������";
		break;
	case FINISHED:
		out << "�����";
		break;
	default:
		break;
	}
	return out;
};

class Order
{
public:
	Order();
	Order(Laptop laptop);
	Order(int num, Laptop laptop, StatusType status);
	~Order();

	void operator=(Order other);

	int GetNum() const;
	Laptop GetLaptop();
	StatusType GetStatus() const;
	void Input();
	void Print() const;
	void SetStatus(StatusType status);
	void SetLaptop(Laptop laptop);
private:
	int num;
	Laptop laptop;
	StatusType status;

	bool CheckArguments(int num, Laptop laptop, StatusType status);
};

void Order::operator=(Order other) {
	this->num = other.num;
	this->laptop = other.laptop;
	this->status = other.status;
}

bool Order::CheckArguments(int num, Laptop laptop, StatusType status) {
	return num > 0 && status >= ONHOLD && status <= FINISHED;
}

Order::Order()
{
	num = 1;
	laptop = Laptop();
	status = ONHOLD;
}

Order::Order(Laptop laptop)
{
	num = 1;
	this->laptop = laptop;
	status = ONHOLD;
}

Order::Order(int num, Laptop laptop, StatusType status)
{
	if (CheckArguments(num, laptop, status)) {
		this->num = num;
		this->laptop = laptop;
		this->status = status;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

Order::~Order()
{
}

int Order::GetNum() const {
	return num;
}

Laptop Order::GetLaptop() {
	return laptop;
}

StatusType Order::GetStatus() const {
	return status;
}

void Order::Input() {
	int num;
	Laptop laptop;
	StatusType status;

	std::cout << "������� ����� ������: ";
	std::cin >> num;
	std::cout << "������� ������ ������ (0 - � ��������, 1 - � �������, 2 - ��������������): ";
	std::cin >> status;
	std::cout << "\t���� ���������� ��������\n";
	laptop.Input();
	if (CheckArguments(num, laptop, status)) {
		this->num = num;
		this->laptop = laptop;
		this->status = status;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

void Order::Print() const {
	StatusType tempStatus = this->status;
	std::cout << "\t���������� � ������\n";
	std::cout << this->num << ". " << this->laptop.GetName() << "\t" << tempStatus << "\n\n";
}

void Order::SetStatus(StatusType status) {
	if (status >= ONHOLD && status <= FINISHED) {
		this->status = status;
		std::cout << "��������� ������ ������� ��������!\n";
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

void Order::SetLaptop(Laptop laptop) {
	this->laptop = laptop;
}