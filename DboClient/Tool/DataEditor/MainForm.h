#pragma once

#include "stdafx.h"
#include "ListData.h"
#include "TableContainer.h"
#include "TableAll.h"
#include "AddEntry.h"


CNtlBitFlagManager flagManager;
CTableContainer* container;
CTableFileNameList fileNameList;



namespace DataEditor {

	using namespace System;
	using namespace System::Text;
	using namespace System::Text::RegularExpressions;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Reflection;
	using namespace System::IO;
	using namespace DataEditor;
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  mainTabs;
	private: System::Windows::Forms::TabPage^  worldTblTab;
	private: System::Windows::Forms::TabPage^  tabTextAll;
	protected:

	protected:


	private: System::Windows::Forms::MenuStrip^  mainMenu;

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ListBox^  worldTblList;
	private: System::Windows::Forms::ToolStripMenuItem^  loadGameDataToolStripMenuItem;
	private: System::Windows::Forms::Panel^  bodyPanel;
	private: System::Windows::Forms::Button^  worldTblSave;

	private: System::Windows::Forms::Button^  worldTblLoad;
	private: System::Windows::Forms::RichTextBox^  log;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  fldWorldTblName;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  cbWorldTblDynamic;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  fldWorldTblCreateCount;
	private: System::Windows::Forms::TextBox^  fldWorldTblDoorType;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  fldWorldTblNpcSp;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  fldWorldTblMobSp;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnTextAllSave;

	private: System::Windows::Forms::Button^  btnTextAllTblLoad;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ListBox^  textAllTblList;
	private: System::Windows::Forms::RichTextBox^  strTextAllTbl;
	private: System::Windows::Forms::TabPage^  tpItem;
	private: System::Windows::Forms::GroupBox^  gbItem;








	private: System::Windows::Forms::CheckBox^  cbValidity;
	private: System::Windows::Forms::TextBox^  tbItemName;


	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  btnItemSave;
	private: System::Windows::Forms::Button^  btnItemLoad;
	private: System::Windows::Forms::ListBox^  lbItems;
	private: System::Windows::Forms::TabPage^  tpNpc;
	private: System::Windows::Forms::TabPage^  tpMob;
	private: System::Windows::Forms::ListBox^  lbNpc;
	private: System::Windows::Forms::GroupBox^  gbNpc;
	private: System::Windows::Forms::CheckBox^  cbNpcValid;

	private: System::Windows::Forms::TextBox^  tbNpcName;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  btnNpcSave;
	private: System::Windows::Forms::Button^  btnNpcLoad;
	private: System::Windows::Forms::TextBox^  tbNpcEP;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  tbNpcLP;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ListBox^  lbMob;
	private: System::Windows::Forms::Button^  btnSaveMob;
	private: System::Windows::Forms::Button^  btnLoadMob;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  tbMobEp;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tbMobLP;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::CheckBox^  cbMobValid;
	private: System::Windows::Forms::TextBox^  tbMobName;
	private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::TabPage^  tpNpcSpawn;
private: System::Windows::Forms::TabPage^  tpMobSpawn;
private: System::Windows::Forms::ListBox^  lbMobSpawns;
private: System::Windows::Forms::Button^  btnMobSpawnSave;
private: System::Windows::Forms::Button^  btnMobSpawnLoad;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::TextBox^  tbMobSpawnDirX;


private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::TextBox^  tbMobSpawnLocX;


private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::TextBox^  tbMobSpawnTblidx;


private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::TabPage^ tpSkills;

private: System::Windows::Forms::TextBox^  tbmobRespawn;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::TextBox^  tbMobSpawnDirZ;

private: System::Windows::Forms::TextBox^  tbMobSpawnLocZ;

private: System::Windows::Forms::TextBox^  tbMobSpawnLocY;
private: System::Windows::Forms::ListBox^  lbNpcSpawn;
private: System::Windows::Forms::Button^  btnNpcSpawnSave;
private: System::Windows::Forms::Button^  btnNpcSpawnLoad;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::TextBox^  tbNpcSpawnDirZ;
private: System::Windows::Forms::TextBox^  tbNpcSpawnLocZ;
private: System::Windows::Forms::TextBox^  tbNpcSpawnLocY;
private: System::Windows::Forms::TextBox^  tbNpcSpawnCooldown;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::TextBox^  tbNpcSpawnDirX;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::TextBox^  tbNpcSpawnLocX;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::TextBox^  TbNpcSpawnNpcTblidx;
private: System::Windows::Forms::Label^  label20;


private: System::Windows::Forms::Label^  label21;

private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::TabPage^  tpMerchant;
private: System::Windows::Forms::ListBox^  lbMerchant;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::TextBox^  tbMerchantSell;

private: System::Windows::Forms::Label^  label23;






private: System::Windows::Forms::TextBox^  tbMerchantTab;


private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Button^  btnMerchantSave;
private: System::Windows::Forms::Button^  btnMerchantLoad;

private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::ListBox^  lbMerchantItems;


private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::TextBox^  tbItemLevel;

private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::TextBox^  tbItemSell;

private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::TextBox^  tbItemCost;

private: System::Windows::Forms::Label^  label29;


private: System::Windows::Forms::Label^  label26;


private: System::Windows::Forms::Label^  label25;


private: System::Windows::Forms::ComboBox^  cbNPCJob;
private: System::Windows::Forms::ComboBox^  cbNpcType;
private: System::Windows::Forms::ComboBox^  cbItemIcons;
private: System::Windows::Forms::PictureBox^  pbItemIcon;
private: System::Windows::Forms::Label^  label32;




private: System::Windows::Forms::TextBox^  textBox18;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::TextBox^  textBox19;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::TextBox^  textBox16;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::TextBox^  textBox17;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::TextBox^  textBox14;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::TextBox^  textBox15;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::TextBox^  textBox7;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::TextBox^  textBox13;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::ComboBox^  comboBox1;
private: System::Windows::Forms::TextBox^  textBox9;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::TextBox^  textBox10;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::TextBox^  textBox11;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::TextBox^  textBox12;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::TextBox^  textBox5;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::TextBox^  textBox6;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::TextBox^  textBox8;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::ComboBox^  cbItemClass;
private: System::Windows::Forms::ComboBox^  cbItemEquipType;

private: System::Windows::Forms::ComboBox^  cbItemType;
private: System::Windows::Forms::TextBox^  textBox3;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::Button^  btnItemAddNew;
private: System::Windows::Forms::TextBox^  fldWorldTblObjSp;
private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::TextBox^  fldVStart1LocZ;
private: System::Windows::Forms::TextBox^  fldVStart1LocY;
private: System::Windows::Forms::TextBox^  fldVStart1LocX;
private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::TextBox^  tbSplitSize;
private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::TextBox^ tbMerchType;
private: System::Windows::Forms::Label^ label56;
private: System::Windows::Forms::TabPage^ tpProps;
private: System::Windows::Forms::Button^ propSaveBtn;
private: System::Windows::Forms::Button^ propLoadBtn;
private: System::Windows::Forms::ListBox^ lbProps;
private: System::Windows::Forms::ToolStripMenuItem^ loadPropertiesToolStripMenuItem;
private: System::Windows::Forms::ListBox^ lbSkills;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::Button^ btnSkillLoad;
private: System::Windows::Forms::ComboBox^ comboBox2;
private: System::Windows::Forms::ComboBox^ comboBox3;
private: System::Windows::Forms::Label^ label57;
private: System::Windows::Forms::Label^ label58;
private: System::Windows::Forms::TextBox^ textBox20;
private: System::Windows::Forms::Label^ label59;
private: System::Windows::Forms::TextBox^ textBox21;
private: System::Windows::Forms::Label^ label60;
private: System::Windows::Forms::CheckBox^ checkBox1;
private: System::Windows::Forms::TextBox^ tbSkillName;
private: System::Windows::Forms::Label^ label61;



















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->mainTabs = (gcnew System::Windows::Forms::TabControl());
			this->worldTblTab = (gcnew System::Windows::Forms::TabPage());
			this->worldTblSave = (gcnew System::Windows::Forms::Button());
			this->worldTblLoad = (gcnew System::Windows::Forms::Button());
			this->bodyPanel = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbSplitSize = (gcnew System::Windows::Forms::TextBox());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->fldVStart1LocZ = (gcnew System::Windows::Forms::TextBox());
			this->fldVStart1LocY = (gcnew System::Windows::Forms::TextBox());
			this->fldVStart1LocX = (gcnew System::Windows::Forms::TextBox());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->fldWorldTblObjSp = (gcnew System::Windows::Forms::TextBox());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->fldWorldTblNpcSp = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->fldWorldTblMobSp = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->fldWorldTblDoorType = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->fldWorldTblCreateCount = (gcnew System::Windows::Forms::TextBox());
			this->cbWorldTblDynamic = (gcnew System::Windows::Forms::CheckBox());
			this->fldWorldTblName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->worldTblList = (gcnew System::Windows::Forms::ListBox());
			this->tabTextAll = (gcnew System::Windows::Forms::TabPage());
			this->btnTextAllSave = (gcnew System::Windows::Forms::Button());
			this->btnTextAllTblLoad = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->strTextAllTbl = (gcnew System::Windows::Forms::RichTextBox());
			this->textAllTblList = (gcnew System::Windows::Forms::ListBox());
			this->tpItem = (gcnew System::Windows::Forms::TabPage());
			this->btnItemAddNew = (gcnew System::Windows::Forms::Button());
			this->gbItem = (gcnew System::Windows::Forms::GroupBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->cbItemClass = (gcnew System::Windows::Forms::ComboBox());
			this->cbItemEquipType = (gcnew System::Windows::Forms::ComboBox());
			this->cbItemType = (gcnew System::Windows::Forms::ComboBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->cbItemIcons = (gcnew System::Windows::Forms::ComboBox());
			this->pbItemIcon = (gcnew System::Windows::Forms::PictureBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->tbItemLevel = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->tbItemSell = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->tbItemCost = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->cbValidity = (gcnew System::Windows::Forms::CheckBox());
			this->tbItemName = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->btnItemSave = (gcnew System::Windows::Forms::Button());
			this->btnItemLoad = (gcnew System::Windows::Forms::Button());
			this->lbItems = (gcnew System::Windows::Forms::ListBox());
			this->tpNpc = (gcnew System::Windows::Forms::TabPage());
			this->lbNpc = (gcnew System::Windows::Forms::ListBox());
			this->gbNpc = (gcnew System::Windows::Forms::GroupBox());
			this->cbNPCJob = (gcnew System::Windows::Forms::ComboBox());
			this->cbNpcType = (gcnew System::Windows::Forms::ComboBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->tbNpcEP = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbNpcLP = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cbNpcValid = (gcnew System::Windows::Forms::CheckBox());
			this->tbNpcName = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnNpcSave = (gcnew System::Windows::Forms::Button());
			this->btnNpcLoad = (gcnew System::Windows::Forms::Button());
			this->tpMerchant = (gcnew System::Windows::Forms::TabPage());
			this->lbMerchant = (gcnew System::Windows::Forms::ListBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->tbMerchType = (gcnew System::Windows::Forms::TextBox());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->lbMerchantItems = (gcnew System::Windows::Forms::ListBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->tbMerchantSell = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->tbMerchantTab = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->btnMerchantSave = (gcnew System::Windows::Forms::Button());
			this->btnMerchantLoad = (gcnew System::Windows::Forms::Button());
			this->tpNpcSpawn = (gcnew System::Windows::Forms::TabPage());
			this->lbNpcSpawn = (gcnew System::Windows::Forms::ListBox());
			this->btnNpcSpawnSave = (gcnew System::Windows::Forms::Button());
			this->btnNpcSpawnLoad = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tbNpcSpawnDirZ = (gcnew System::Windows::Forms::TextBox());
			this->tbNpcSpawnLocZ = (gcnew System::Windows::Forms::TextBox());
			this->tbNpcSpawnLocY = (gcnew System::Windows::Forms::TextBox());
			this->tbNpcSpawnCooldown = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->tbNpcSpawnDirX = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->tbNpcSpawnLocX = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->TbNpcSpawnNpcTblidx = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tpMob = (gcnew System::Windows::Forms::TabPage());
			this->lbMob = (gcnew System::Windows::Forms::ListBox());
			this->btnSaveMob = (gcnew System::Windows::Forms::Button());
			this->btnLoadMob = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tbMobEp = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tbMobLP = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->cbMobValid = (gcnew System::Windows::Forms::CheckBox());
			this->tbMobName = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tpMobSpawn = (gcnew System::Windows::Forms::TabPage());
			this->lbMobSpawns = (gcnew System::Windows::Forms::ListBox());
			this->btnMobSpawnSave = (gcnew System::Windows::Forms::Button());
			this->btnMobSpawnLoad = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tbMobSpawnDirZ = (gcnew System::Windows::Forms::TextBox());
			this->tbMobSpawnLocZ = (gcnew System::Windows::Forms::TextBox());
			this->tbMobSpawnLocY = (gcnew System::Windows::Forms::TextBox());
			this->tbmobRespawn = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->tbMobSpawnDirX = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tbMobSpawnLocX = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->tbMobSpawnTblidx = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->tpSkills = (gcnew System::Windows::Forms::TabPage());
			this->tpProps = (gcnew System::Windows::Forms::TabPage());
			this->propSaveBtn = (gcnew System::Windows::Forms::Button());
			this->propLoadBtn = (gcnew System::Windows::Forms::Button());
			this->lbProps = (gcnew System::Windows::Forms::ListBox());
			this->log = (gcnew System::Windows::Forms::RichTextBox());
			this->mainMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadGameDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadPropertiesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->tbSkillName = (gcnew System::Windows::Forms::TextBox());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->lbSkills = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnSkillLoad = (gcnew System::Windows::Forms::Button());
			this->mainTabs->SuspendLayout();
			this->worldTblTab->SuspendLayout();
			this->bodyPanel->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabTextAll->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tpItem->SuspendLayout();
			this->gbItem->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbItemIcon))->BeginInit();
			this->tpNpc->SuspendLayout();
			this->gbNpc->SuspendLayout();
			this->tpMerchant->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tpNpcSpawn->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tpMob->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tpMobSpawn->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tpSkills->SuspendLayout();
			this->tpProps->SuspendLayout();
			this->mainMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainTabs
			// 
			this->mainTabs->Controls->Add(this->worldTblTab);
			this->mainTabs->Controls->Add(this->tabTextAll);
			this->mainTabs->Controls->Add(this->tpItem);
			this->mainTabs->Controls->Add(this->tpNpc);
			this->mainTabs->Controls->Add(this->tpMerchant);
			this->mainTabs->Controls->Add(this->tpNpcSpawn);
			this->mainTabs->Controls->Add(this->tpMob);
			this->mainTabs->Controls->Add(this->tpMobSpawn);
			this->mainTabs->Controls->Add(this->tpSkills);
			this->mainTabs->Controls->Add(this->tpProps);
			this->mainTabs->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainTabs->Location = System::Drawing::Point(0, 24);
			this->mainTabs->Name = L"mainTabs";
			this->mainTabs->SelectedIndex = 0;
			this->mainTabs->Size = System::Drawing::Size(746, 481);
			this->mainTabs->TabIndex = 0;
			// 
			// worldTblTab
			// 
			this->worldTblTab->Controls->Add(this->worldTblSave);
			this->worldTblTab->Controls->Add(this->worldTblLoad);
			this->worldTblTab->Controls->Add(this->bodyPanel);
			this->worldTblTab->Controls->Add(this->worldTblList);
			this->worldTblTab->Location = System::Drawing::Point(4, 22);
			this->worldTblTab->Name = L"worldTblTab";
			this->worldTblTab->Padding = System::Windows::Forms::Padding(3);
			this->worldTblTab->Size = System::Drawing::Size(738, 455);
			this->worldTblTab->TabIndex = 0;
			this->worldTblTab->Text = L"World Table";
			this->worldTblTab->UseVisualStyleBackColor = true;
			// 
			// worldTblSave
			// 
			this->worldTblSave->Enabled = false;
			this->worldTblSave->Location = System::Drawing::Point(169, 392);
			this->worldTblSave->Name = L"worldTblSave";
			this->worldTblSave->Size = System::Drawing::Size(75, 28);
			this->worldTblSave->TabIndex = 3;
			this->worldTblSave->Text = L"Save";
			this->worldTblSave->UseVisualStyleBackColor = true;
			this->worldTblSave->Click += gcnew System::EventHandler(this, &MainForm::worldTblSave_Click);
			// 
			// worldTblLoad
			// 
			this->worldTblLoad->Enabled = false;
			this->worldTblLoad->Location = System::Drawing::Point(8, 392);
			this->worldTblLoad->Name = L"worldTblLoad";
			this->worldTblLoad->Size = System::Drawing::Size(75, 28);
			this->worldTblLoad->TabIndex = 2;
			this->worldTblLoad->Text = L"Load";
			this->worldTblLoad->UseVisualStyleBackColor = true;
			this->worldTblLoad->Click += gcnew System::EventHandler(this, &MainForm::worldTblLoad_Click);
			// 
			// bodyPanel
			// 
			this->bodyPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->bodyPanel->Controls->Add(this->groupBox1);
			this->bodyPanel->Location = System::Drawing::Point(250, 6);
			this->bodyPanel->Name = L"bodyPanel";
			this->bodyPanel->Size = System::Drawing::Size(480, 446);
			this->bodyPanel->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbSplitSize);
			this->groupBox1->Controls->Add(this->label55);
			this->groupBox1->Controls->Add(this->fldVStart1LocZ);
			this->groupBox1->Controls->Add(this->fldVStart1LocY);
			this->groupBox1->Controls->Add(this->fldVStart1LocX);
			this->groupBox1->Controls->Add(this->label54);
			this->groupBox1->Controls->Add(this->fldWorldTblObjSp);
			this->groupBox1->Controls->Add(this->label53);
			this->groupBox1->Controls->Add(this->fldWorldTblNpcSp);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->fldWorldTblMobSp);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->fldWorldTblDoorType);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->fldWorldTblCreateCount);
			this->groupBox1->Controls->Add(this->cbWorldTblDynamic);
			this->groupBox1->Controls->Add(this->fldWorldTblName);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(480, 446);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"World Data";
			// 
			// tbSplitSize
			// 
			this->tbSplitSize->Location = System::Drawing::Point(106, 172);
			this->tbSplitSize->Name = L"tbSplitSize";
			this->tbSplitSize->Size = System::Drawing::Size(65, 20);
			this->tbSplitSize->TabIndex = 19;
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(8, 175);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(50, 13);
			this->label55->TabIndex = 18;
			this->label55->Text = L"Split Size";
			// 
			// fldVStart1LocZ
			// 
			this->fldVStart1LocZ->Location = System::Drawing::Point(245, 147);
			this->fldVStart1LocZ->Name = L"fldVStart1LocZ";
			this->fldVStart1LocZ->Size = System::Drawing::Size(62, 20);
			this->fldVStart1LocZ->TabIndex = 17;
			// 
			// fldVStart1LocY
			// 
			this->fldVStart1LocY->Location = System::Drawing::Point(177, 147);
			this->fldVStart1LocY->Name = L"fldVStart1LocY";
			this->fldVStart1LocY->Size = System::Drawing::Size(62, 20);
			this->fldVStart1LocY->TabIndex = 16;
			// 
			// fldVStart1LocX
			// 
			this->fldVStart1LocX->Location = System::Drawing::Point(106, 147);
			this->fldVStart1LocX->Name = L"fldVStart1LocX";
			this->fldVStart1LocX->Size = System::Drawing::Size(65, 20);
			this->fldVStart1LocX->TabIndex = 15;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(8, 150);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(59, 13);
			this->label54->TabIndex = 14;
			this->label54->Text = L"vStart1Loc";
			// 
			// fldWorldTblObjSp
			// 
			this->fldWorldTblObjSp->Location = System::Drawing::Point(106, 121);
			this->fldWorldTblObjSp->Name = L"fldWorldTblObjSp";
			this->fldWorldTblObjSp->Size = System::Drawing::Size(364, 20);
			this->fldWorldTblObjSp->TabIndex = 13;
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(7, 124);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(89, 13);
			this->label53->TabIndex = 12;
			this->label53->Text = L"Obj Spawn Table";
			// 
			// fldWorldTblNpcSp
			// 
			this->fldWorldTblNpcSp->Location = System::Drawing::Point(106, 95);
			this->fldWorldTblNpcSp->Name = L"fldWorldTblNpcSp";
			this->fldWorldTblNpcSp->Size = System::Drawing::Size(364, 20);
			this->fldWorldTblNpcSp->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 98);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Npc Spawn Table";
			// 
			// fldWorldTblMobSp
			// 
			this->fldWorldTblMobSp->Location = System::Drawing::Point(106, 69);
			this->fldWorldTblMobSp->Name = L"fldWorldTblMobSp";
			this->fldWorldTblMobSp->Size = System::Drawing::Size(364, 20);
			this->fldWorldTblMobSp->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 72);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Mob Spawn Table";
			// 
			// fldWorldTblDoorType
			// 
			this->fldWorldTblDoorType->Location = System::Drawing::Point(230, 43);
			this->fldWorldTblDoorType->Name = L"fldWorldTblDoorType";
			this->fldWorldTblDoorType->Size = System::Drawing::Size(100, 20);
			this->fldWorldTblDoorType->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(167, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Door Type";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Create Count";
			// 
			// fldWorldTblCreateCount
			// 
			this->fldWorldTblCreateCount->Location = System::Drawing::Point(83, 43);
			this->fldWorldTblCreateCount->Name = L"fldWorldTblCreateCount";
			this->fldWorldTblCreateCount->Size = System::Drawing::Size(78, 20);
			this->fldWorldTblCreateCount->TabIndex = 4;
			// 
			// cbWorldTblDynamic
			// 
			this->cbWorldTblDynamic->AutoSize = true;
			this->cbWorldTblDynamic->Location = System::Drawing::Point(362, 19);
			this->cbWorldTblDynamic->Name = L"cbWorldTblDynamic";
			this->cbWorldTblDynamic->Size = System::Drawing::Size(67, 17);
			this->cbWorldTblDynamic->TabIndex = 3;
			this->cbWorldTblDynamic->Text = L"Dynamic";
			this->cbWorldTblDynamic->UseVisualStyleBackColor = true;
			// 
			// fldWorldTblName
			// 
			this->fldWorldTblName->Location = System::Drawing::Point(48, 17);
			this->fldWorldTblName->Name = L"fldWorldTblName";
			this->fldWorldTblName->Size = System::Drawing::Size(308, 20);
			this->fldWorldTblName->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name";
			// 
			// worldTblList
			// 
			this->worldTblList->FormattingEnabled = true;
			this->worldTblList->Location = System::Drawing::Point(8, 6);
			this->worldTblList->Name = L"worldTblList";
			this->worldTblList->Size = System::Drawing::Size(236, 381);
			this->worldTblList->TabIndex = 0;
			this->worldTblList->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::worldTblList_SelectedIndexChanged);
			// 
			// tabTextAll
			// 
			this->tabTextAll->Controls->Add(this->btnTextAllSave);
			this->tabTextAll->Controls->Add(this->btnTextAllTblLoad);
			this->tabTextAll->Controls->Add(this->panel1);
			this->tabTextAll->Controls->Add(this->textAllTblList);
			this->tabTextAll->Location = System::Drawing::Point(4, 22);
			this->tabTextAll->Name = L"tabTextAll";
			this->tabTextAll->Padding = System::Windows::Forms::Padding(3);
			this->tabTextAll->Size = System::Drawing::Size(738, 455);
			this->tabTextAll->TabIndex = 1;
			this->tabTextAll->Text = L"Text All Table";
			this->tabTextAll->UseVisualStyleBackColor = true;
			// 
			// btnTextAllSave
			// 
			this->btnTextAllSave->Enabled = false;
			this->btnTextAllSave->Location = System::Drawing::Point(169, 391);
			this->btnTextAllSave->Name = L"btnTextAllSave";
			this->btnTextAllSave->Size = System::Drawing::Size(75, 28);
			this->btnTextAllSave->TabIndex = 7;
			this->btnTextAllSave->Text = L"Save";
			this->btnTextAllSave->UseVisualStyleBackColor = true;
			// 
			// btnTextAllTblLoad
			// 
			this->btnTextAllTblLoad->Enabled = false;
			this->btnTextAllTblLoad->Location = System::Drawing::Point(8, 391);
			this->btnTextAllTblLoad->Name = L"btnTextAllTblLoad";
			this->btnTextAllTblLoad->Size = System::Drawing::Size(75, 28);
			this->btnTextAllTblLoad->TabIndex = 6;
			this->btnTextAllTblLoad->Text = L"Load";
			this->btnTextAllTblLoad->UseVisualStyleBackColor = true;
			this->btnTextAllTblLoad->Click += gcnew System::EventHandler(this, &MainForm::btnTextAllTblLoad_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Location = System::Drawing::Point(250, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(480, 446);
			this->panel1->TabIndex = 5;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->strTextAllTbl);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(0, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(480, 446);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Text All Data";
			// 
			// strTextAllTbl
			// 
			this->strTextAllTbl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->strTextAllTbl->Location = System::Drawing::Point(3, 16);
			this->strTextAllTbl->Name = L"strTextAllTbl";
			this->strTextAllTbl->Size = System::Drawing::Size(474, 427);
			this->strTextAllTbl->TabIndex = 0;
			this->strTextAllTbl->Text = L"";
			// 
			// textAllTblList
			// 
			this->textAllTblList->FormattingEnabled = true;
			this->textAllTblList->Location = System::Drawing::Point(8, 5);
			this->textAllTblList->Name = L"textAllTblList";
			this->textAllTblList->Size = System::Drawing::Size(236, 381);
			this->textAllTblList->TabIndex = 4;
			this->textAllTblList->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::textAllTblList_SelectedIndexChanged);
			// 
			// tpItem
			// 
			this->tpItem->Controls->Add(this->btnItemAddNew);
			this->tpItem->Controls->Add(this->gbItem);
			this->tpItem->Controls->Add(this->btnItemSave);
			this->tpItem->Controls->Add(this->btnItemLoad);
			this->tpItem->Controls->Add(this->lbItems);
			this->tpItem->Location = System::Drawing::Point(4, 22);
			this->tpItem->Name = L"tpItem";
			this->tpItem->Padding = System::Windows::Forms::Padding(3);
			this->tpItem->Size = System::Drawing::Size(738, 455);
			this->tpItem->TabIndex = 2;
			this->tpItem->Text = L"Item Table";
			this->tpItem->UseVisualStyleBackColor = true;
			// 
			// btnItemAddNew
			// 
			this->btnItemAddNew->Enabled = false;
			this->btnItemAddNew->Location = System::Drawing::Point(88, 393);
			this->btnItemAddNew->Name = L"btnItemAddNew";
			this->btnItemAddNew->Size = System::Drawing::Size(75, 28);
			this->btnItemAddNew->TabIndex = 11;
			this->btnItemAddNew->Text = L"AddNew";
			this->btnItemAddNew->UseVisualStyleBackColor = true;
			this->btnItemAddNew->Click += gcnew System::EventHandler(this, &MainForm::btnItemAddNew_Click);
			// 
			// gbItem
			// 
			this->gbItem->Controls->Add(this->textBox18);
			this->gbItem->Controls->Add(this->label51);
			this->gbItem->Controls->Add(this->textBox19);
			this->gbItem->Controls->Add(this->label52);
			this->gbItem->Controls->Add(this->textBox16);
			this->gbItem->Controls->Add(this->label49);
			this->gbItem->Controls->Add(this->textBox17);
			this->gbItem->Controls->Add(this->label50);
			this->gbItem->Controls->Add(this->textBox14);
			this->gbItem->Controls->Add(this->label47);
			this->gbItem->Controls->Add(this->textBox15);
			this->gbItem->Controls->Add(this->label48);
			this->gbItem->Controls->Add(this->textBox7);
			this->gbItem->Controls->Add(this->label45);
			this->gbItem->Controls->Add(this->textBox13);
			this->gbItem->Controls->Add(this->label46);
			this->gbItem->Controls->Add(this->textBox1);
			this->gbItem->Controls->Add(this->comboBox1);
			this->gbItem->Controls->Add(this->textBox9);
			this->gbItem->Controls->Add(this->label41);
			this->gbItem->Controls->Add(this->textBox10);
			this->gbItem->Controls->Add(this->label42);
			this->gbItem->Controls->Add(this->textBox11);
			this->gbItem->Controls->Add(this->label43);
			this->gbItem->Controls->Add(this->textBox12);
			this->gbItem->Controls->Add(this->label44);
			this->gbItem->Controls->Add(this->textBox5);
			this->gbItem->Controls->Add(this->label37);
			this->gbItem->Controls->Add(this->textBox6);
			this->gbItem->Controls->Add(this->label38);
			this->gbItem->Controls->Add(this->label39);
			this->gbItem->Controls->Add(this->textBox8);
			this->gbItem->Controls->Add(this->label40);
			this->gbItem->Controls->Add(this->cbItemClass);
			this->gbItem->Controls->Add(this->cbItemEquipType);
			this->gbItem->Controls->Add(this->cbItemType);
			this->gbItem->Controls->Add(this->textBox3);
			this->gbItem->Controls->Add(this->label35);
			this->gbItem->Controls->Add(this->textBox4);
			this->gbItem->Controls->Add(this->label36);
			this->gbItem->Controls->Add(this->label33);
			this->gbItem->Controls->Add(this->textBox2);
			this->gbItem->Controls->Add(this->label34);
			this->gbItem->Controls->Add(this->cbItemIcons);
			this->gbItem->Controls->Add(this->pbItemIcon);
			this->gbItem->Controls->Add(this->label32);
			this->gbItem->Controls->Add(this->label30);
			this->gbItem->Controls->Add(this->tbItemLevel);
			this->gbItem->Controls->Add(this->label31);
			this->gbItem->Controls->Add(this->tbItemSell);
			this->gbItem->Controls->Add(this->label28);
			this->gbItem->Controls->Add(this->tbItemCost);
			this->gbItem->Controls->Add(this->label29);
			this->gbItem->Controls->Add(this->label26);
			this->gbItem->Controls->Add(this->label25);
			this->gbItem->Controls->Add(this->cbValidity);
			this->gbItem->Controls->Add(this->tbItemName);
			this->gbItem->Controls->Add(this->label10);
			this->gbItem->Location = System::Drawing::Point(250, 6);
			this->gbItem->Name = L"gbItem";
			this->gbItem->Size = System::Drawing::Size(482, 449);
			this->gbItem->TabIndex = 10;
			this->gbItem->TabStop = false;
			this->gbItem->Text = L"Item Data";
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(300, 360);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(142, 20);
			this->textBox18->TabIndex = 64;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(224, 363);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(64, 13);
			this->label51->TabIndex = 63;
			this->label51->Text = L"Speed Rate";
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(72, 360);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(124, 20);
			this->textBox19->TabIndex = 62;
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(6, 363);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(72, 13);
			this->label52->TabIndex = 61;
			this->label52->Text = L"Range Bonus";
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(300, 334);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(142, 20);
			this->textBox16->TabIndex = 60;
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(224, 337);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(51, 13);
			this->label49->TabIndex = 59;
			this->label49->Text = L"EngD Up";
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(72, 334);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(124, 20);
			this->textBox17->TabIndex = 58;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(6, 337);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(51, 13);
			this->label50->TabIndex = 57;
			this->label50->Text = L"EngO Up";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(300, 308);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(142, 20);
			this->textBox14->TabIndex = 56;
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(224, 311);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(55, 13);
			this->label47->TabIndex = 55;
			this->label47->Text = L"PhysD Up";
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(72, 308);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(124, 20);
			this->textBox15->TabIndex = 54;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(6, 311);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(55, 13);
			this->label48->TabIndex = 53;
			this->label48->Text = L"PhysO Up";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(300, 282);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(142, 20);
			this->textBox7->TabIndex = 52;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(224, 285);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(69, 13);
			this->label45->TabIndex = 51;
			this->label45->Text = L"Eng Defense";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(72, 282);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(124, 20);
			this->textBox13->TabIndex = 50;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(6, 285);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(66, 13);
			this->label46->TabIndex = 49;
			this->label46->Text = L"Eng Offense";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(300, 178);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(142, 20);
			this->textBox1->TabIndex = 48;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(302, 126);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(142, 21);
			this->comboBox1->TabIndex = 47;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(300, 256);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(142, 20);
			this->textBox9->TabIndex = 46;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(224, 259);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(73, 13);
			this->label41->TabIndex = 45;
			this->label41->Text = L"Phys Defense";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(72, 256);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(124, 20);
			this->textBox10->TabIndex = 44;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(6, 259);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(70, 13);
			this->label42->TabIndex = 43;
			this->label42->Text = L"Phys Offense";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(301, 230);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(141, 20);
			this->textBox11->TabIndex = 42;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(224, 233);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(57, 13);
			this->label43->TabIndex = 41;
			this->label43->Text = L"DurabilityC";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(72, 230);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(124, 20);
			this->textBox12->TabIndex = 40;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(6, 228);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(46, 13);
			this->label44->TabIndex = 39;
			this->label44->Text = L"Attribute";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(301, 204);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(142, 20);
			this->textBox5->TabIndex = 38;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(225, 207);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(50, 13);
			this->label37->TabIndex = 37;
			this->label37->Text = L"Durability";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(73, 204);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(124, 20);
			this->textBox6->TabIndex = 36;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(7, 202);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(33, 13);
			this->label38->TabIndex = 35;
			this->label38->Text = L"Rank";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(225, 181);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(58, 13);
			this->label39->TabIndex = 33;
			this->label39->Text = L"Max Stack";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(73, 178);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(124, 20);
			this->textBox8->TabIndex = 32;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(7, 176);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(48, 13);
			this->label40->TabIndex = 31;
			this->label40->Text = L"Function";
			// 
			// cbItemClass
			// 
			this->cbItemClass->FormattingEnabled = true;
			this->cbItemClass->Location = System::Drawing::Point(302, 99);
			this->cbItemClass->Name = L"cbItemClass";
			this->cbItemClass->Size = System::Drawing::Size(141, 21);
			this->cbItemClass->TabIndex = 30;
			// 
			// cbItemEquipType
			// 
			this->cbItemEquipType->FormattingEnabled = true;
			this->cbItemEquipType->Location = System::Drawing::Point(301, 46);
			this->cbItemEquipType->Name = L"cbItemEquipType";
			this->cbItemEquipType->Size = System::Drawing::Size(142, 21);
			this->cbItemEquipType->TabIndex = 29;
			// 
			// cbItemType
			// 
			this->cbItemType->FormattingEnabled = true;
			this->cbItemType->Location = System::Drawing::Point(73, 46);
			this->cbItemType->Name = L"cbItemType";
			this->cbItemType->Size = System::Drawing::Size(124, 21);
			this->cbItemType->TabIndex = 28;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(301, 152);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(142, 20);
			this->textBox3->TabIndex = 27;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(225, 155);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(67, 13);
			this->label35->TabIndex = 26;
			this->label35->Text = L"Model Name";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(73, 152);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(124, 20);
			this->textBox4->TabIndex = 25;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(7, 150);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(60, 13);
			this->label36->TabIndex = 24;
			this->label36->Text = L"ModelType";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(225, 129);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(55, 13);
			this->label33->TabIndex = 22;
			this->label33->Text = L"Equip Slot";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(73, 126);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(124, 20);
			this->textBox2->TabIndex = 21;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(7, 124);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(42, 13);
			this->label34->TabIndex = 20;
			this->label34->Text = L"NameT";
			// 
			// cbItemIcons
			// 
			this->cbItemIcons->FormattingEnabled = true;
			this->cbItemIcons->Location = System::Drawing::Point(48, 425);
			this->cbItemIcons->Name = L"cbItemIcons";
			this->cbItemIcons->Size = System::Drawing::Size(121, 21);
			this->cbItemIcons->TabIndex = 19;
			this->cbItemIcons->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cbItemIcons_SelectedIndexChanged);
			// 
			// pbItemIcon
			// 
			this->pbItemIcon->Location = System::Drawing::Point(175, 414);
			this->pbItemIcon->Name = L"pbItemIcon";
			this->pbItemIcon->Size = System::Drawing::Size(32, 32);
			this->pbItemIcon->TabIndex = 18;
			this->pbItemIcon->TabStop = false;
			this->pbItemIcon->Click += gcnew System::EventHandler(this, &MainForm::pbItemIcon_Click);
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(10, 433);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(28, 13);
			this->label32->TabIndex = 16;
			this->label32->Text = L"Icon";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(224, 102);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(32, 13);
			this->label30->TabIndex = 14;
			this->label30->Text = L"Class";
			// 
			// tbItemLevel
			// 
			this->tbItemLevel->Location = System::Drawing::Point(73, 99);
			this->tbItemLevel->Name = L"tbItemLevel";
			this->tbItemLevel->Size = System::Drawing::Size(124, 20);
			this->tbItemLevel->TabIndex = 13;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(7, 98);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(33, 13);
			this->label31->TabIndex = 12;
			this->label31->Text = L"Level";
			// 
			// tbItemSell
			// 
			this->tbItemSell->Location = System::Drawing::Point(302, 73);
			this->tbItemSell->Name = L"tbItemSell";
			this->tbItemSell->Size = System::Drawing::Size(141, 20);
			this->tbItemSell->TabIndex = 11;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(225, 76);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(24, 13);
			this->label28->TabIndex = 10;
			this->label28->Text = L"Sell";
			// 
			// tbItemCost
			// 
			this->tbItemCost->Location = System::Drawing::Point(73, 73);
			this->tbItemCost->Name = L"tbItemCost";
			this->tbItemCost->Size = System::Drawing::Size(124, 20);
			this->tbItemCost->TabIndex = 9;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(7, 72);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(28, 13);
			this->label29->TabIndex = 8;
			this->label29->Text = L"Cost";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(224, 49);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(61, 13);
			this->label26->TabIndex = 6;
			this->label26->Text = L"Equip Type";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(7, 46);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(31, 13);
			this->label25->TabIndex = 4;
			this->label25->Text = L"Type";
			// 
			// cbValidity
			// 
			this->cbValidity->AutoSize = true;
			this->cbValidity->Location = System::Drawing::Point(362, 19);
			this->cbValidity->Name = L"cbValidity";
			this->cbValidity->Size = System::Drawing::Size(83, 17);
			this->cbValidity->TabIndex = 3;
			this->cbValidity->Text = L"Validity Able";
			this->cbValidity->UseVisualStyleBackColor = true;
			// 
			// tbItemName
			// 
			this->tbItemName->Location = System::Drawing::Point(72, 17);
			this->tbItemName->Name = L"tbItemName";
			this->tbItemName->Size = System::Drawing::Size(284, 20);
			this->tbItemName->TabIndex = 1;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(7, 20);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 13);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Name";
			// 
			// btnItemSave
			// 
			this->btnItemSave->Enabled = false;
			this->btnItemSave->Location = System::Drawing::Point(169, 393);
			this->btnItemSave->Name = L"btnItemSave";
			this->btnItemSave->Size = System::Drawing::Size(75, 28);
			this->btnItemSave->TabIndex = 9;
			this->btnItemSave->Text = L"Save";
			this->btnItemSave->UseVisualStyleBackColor = true;
			// 
			// btnItemLoad
			// 
			this->btnItemLoad->Enabled = false;
			this->btnItemLoad->Location = System::Drawing::Point(8, 393);
			this->btnItemLoad->Name = L"btnItemLoad";
			this->btnItemLoad->Size = System::Drawing::Size(75, 28);
			this->btnItemLoad->TabIndex = 8;
			this->btnItemLoad->Text = L"Load";
			this->btnItemLoad->UseVisualStyleBackColor = true;
			this->btnItemLoad->Click += gcnew System::EventHandler(this, &MainForm::btnItemLoad_Click);
			// 
			// lbItems
			// 
			this->lbItems->FormattingEnabled = true;
			this->lbItems->Location = System::Drawing::Point(8, 6);
			this->lbItems->Name = L"lbItems";
			this->lbItems->Size = System::Drawing::Size(236, 381);
			this->lbItems->TabIndex = 1;
			this->lbItems->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::lbItems_SelectedIndexChanged);
			// 
			// tpNpc
			// 
			this->tpNpc->Controls->Add(this->lbNpc);
			this->tpNpc->Controls->Add(this->gbNpc);
			this->tpNpc->Controls->Add(this->btnNpcSave);
			this->tpNpc->Controls->Add(this->btnNpcLoad);
			this->tpNpc->Location = System::Drawing::Point(4, 22);
			this->tpNpc->Name = L"tpNpc";
			this->tpNpc->Size = System::Drawing::Size(738, 455);
			this->tpNpc->TabIndex = 3;
			this->tpNpc->Text = L"NPC Table";
			this->tpNpc->UseVisualStyleBackColor = true;
			// 
			// lbNpc
			// 
			this->lbNpc->FormattingEnabled = true;
			this->lbNpc->Location = System::Drawing::Point(7, 3);
			this->lbNpc->Name = L"lbNpc";
			this->lbNpc->Size = System::Drawing::Size(236, 381);
			this->lbNpc->TabIndex = 11;
			this->lbNpc->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::lbNpc_SelectedIndexChanged);
			// 
			// gbNpc
			// 
			this->gbNpc->Controls->Add(this->cbNPCJob);
			this->gbNpc->Controls->Add(this->cbNpcType);
			this->gbNpc->Controls->Add(this->label22);
			this->gbNpc->Controls->Add(this->label21);
			this->gbNpc->Controls->Add(this->tbNpcEP);
			this->gbNpc->Controls->Add(this->label8);
			this->gbNpc->Controls->Add(this->tbNpcLP);
			this->gbNpc->Controls->Add(this->label7);
			this->gbNpc->Controls->Add(this->cbNpcValid);
			this->gbNpc->Controls->Add(this->tbNpcName);
			this->gbNpc->Controls->Add(this->label6);
			this->gbNpc->Location = System::Drawing::Point(249, 3);
			this->gbNpc->Name = L"gbNpc";
			this->gbNpc->Size = System::Drawing::Size(482, 449);
			this->gbNpc->TabIndex = 14;
			this->gbNpc->TabStop = false;
			this->gbNpc->Text = L"NPC Data";
			// 
			// cbNPCJob
			// 
			this->cbNPCJob->FormattingEnabled = true;
			this->cbNPCJob->Location = System::Drawing::Point(64, 96);
			this->cbNPCJob->Name = L"cbNPCJob";
			this->cbNPCJob->Size = System::Drawing::Size(121, 21);
			this->cbNPCJob->TabIndex = 13;
			// 
			// cbNpcType
			// 
			this->cbNpcType->FormattingEnabled = true;
			this->cbNpcType->Location = System::Drawing::Point(64, 69);
			this->cbNpcType->Name = L"cbNpcType";
			this->cbNpcType->Size = System::Drawing::Size(121, 21);
			this->cbNpcType->TabIndex = 12;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(7, 99);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(51, 13);
			this->label22->TabIndex = 10;
			this->label22->Text = L"Job Type";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(7, 72);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(56, 13);
			this->label21->TabIndex = 8;
			this->label21->Text = L"NPC Type";
			// 
			// tbNpcEP
			// 
			this->tbNpcEP->Location = System::Drawing::Point(195, 43);
			this->tbNpcEP->Name = L"tbNpcEP";
			this->tbNpcEP->Size = System::Drawing::Size(65, 20);
			this->tbNpcEP->TabIndex = 7;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(139, 46);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(50, 13);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Basic EP";
			// 
			// tbNpcLP
			// 
			this->tbNpcLP->Location = System::Drawing::Point(62, 43);
			this->tbNpcLP->Name = L"tbNpcLP";
			this->tbNpcLP->Size = System::Drawing::Size(65, 20);
			this->tbNpcLP->TabIndex = 5;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(7, 46);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 13);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Basic LP";
			// 
			// cbNpcValid
			// 
			this->cbNpcValid->AutoSize = true;
			this->cbNpcValid->Location = System::Drawing::Point(362, 19);
			this->cbNpcValid->Name = L"cbNpcValid";
			this->cbNpcValid->Size = System::Drawing::Size(83, 17);
			this->cbNpcValid->TabIndex = 3;
			this->cbNpcValid->Text = L"Validity Able";
			this->cbNpcValid->UseVisualStyleBackColor = true;
			// 
			// tbNpcName
			// 
			this->tbNpcName->Location = System::Drawing::Point(48, 17);
			this->tbNpcName->Name = L"tbNpcName";
			this->tbNpcName->Size = System::Drawing::Size(308, 20);
			this->tbNpcName->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 20);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Name";
			// 
			// btnNpcSave
			// 
			this->btnNpcSave->Enabled = false;
			this->btnNpcSave->Location = System::Drawing::Point(168, 390);
			this->btnNpcSave->Name = L"btnNpcSave";
			this->btnNpcSave->Size = System::Drawing::Size(75, 28);
			this->btnNpcSave->TabIndex = 13;
			this->btnNpcSave->Text = L"Save";
			this->btnNpcSave->UseVisualStyleBackColor = true;
			// 
			// btnNpcLoad
			// 
			this->btnNpcLoad->Enabled = false;
			this->btnNpcLoad->Location = System::Drawing::Point(7, 390);
			this->btnNpcLoad->Name = L"btnNpcLoad";
			this->btnNpcLoad->Size = System::Drawing::Size(75, 28);
			this->btnNpcLoad->TabIndex = 12;
			this->btnNpcLoad->Text = L"Load";
			this->btnNpcLoad->UseVisualStyleBackColor = true;
			this->btnNpcLoad->Click += gcnew System::EventHandler(this, &MainForm::btnNpcLoad_Click);
			// 
			// tpMerchant
			// 
			this->tpMerchant->Controls->Add(this->lbMerchant);
			this->tpMerchant->Controls->Add(this->groupBox6);
			this->tpMerchant->Controls->Add(this->btnMerchantSave);
			this->tpMerchant->Controls->Add(this->btnMerchantLoad);
			this->tpMerchant->Location = System::Drawing::Point(4, 22);
			this->tpMerchant->Name = L"tpMerchant";
			this->tpMerchant->Padding = System::Windows::Forms::Padding(3);
			this->tpMerchant->Size = System::Drawing::Size(738, 455);
			this->tpMerchant->TabIndex = 8;
			this->tpMerchant->Text = L"Merchant Table";
			this->tpMerchant->UseVisualStyleBackColor = true;
			// 
			// lbMerchant
			// 
			this->lbMerchant->FormattingEnabled = true;
			this->lbMerchant->Location = System::Drawing::Point(7, 3);
			this->lbMerchant->Name = L"lbMerchant";
			this->lbMerchant->Size = System::Drawing::Size(236, 381);
			this->lbMerchant->TabIndex = 15;
			this->lbMerchant->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::lbMerchant_SelectedIndexChanged);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->tbMerchType);
			this->groupBox6->Controls->Add(this->label56);
			this->groupBox6->Controls->Add(this->lbMerchantItems);
			this->groupBox6->Controls->Add(this->label24);
			this->groupBox6->Controls->Add(this->tbMerchantSell);
			this->groupBox6->Controls->Add(this->label23);
			this->groupBox6->Controls->Add(this->tbMerchantTab);
			this->groupBox6->Controls->Add(this->label27);
			this->groupBox6->Location = System::Drawing::Point(249, 3);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(482, 449);
			this->groupBox6->TabIndex = 18;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Merchant Data";
			// 
			// tbMerchType
			// 
			this->tbMerchType->Location = System::Drawing::Point(82, 19);
			this->tbMerchType->Name = L"tbMerchType";
			this->tbMerchType->Size = System::Drawing::Size(199, 20);
			this->tbMerchType->TabIndex = 21;
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(6, 22);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(64, 13);
			this->label56->TabIndex = 20;
			this->label56->Text = L"Merch Type";
			// 
			// lbMerchantItems
			// 
			this->lbMerchantItems->FormattingEnabled = true;
			this->lbMerchantItems->Location = System::Drawing::Point(82, 105);
			this->lbMerchantItems->Name = L"lbMerchantItems";
			this->lbMerchantItems->Size = System::Drawing::Size(199, 147);
			this->lbMerchantItems->TabIndex = 19;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(6, 105);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(32, 13);
			this->label24->TabIndex = 12;
			this->label24->Text = L"Items";
			// 
			// tbMerchantSell
			// 
			this->tbMerchantSell->Location = System::Drawing::Point(82, 74);
			this->tbMerchantSell->Name = L"tbMerchantSell";
			this->tbMerchantSell->Size = System::Drawing::Size(199, 20);
			this->tbMerchantSell->TabIndex = 11;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(6, 77);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(69, 13);
			this->label23->TabIndex = 10;
			this->label23->Text = L"Sell Catagory";
			// 
			// tbMerchantTab
			// 
			this->tbMerchantTab->Location = System::Drawing::Point(82, 45);
			this->tbMerchantTab->Name = L"tbMerchantTab";
			this->tbMerchantTab->Size = System::Drawing::Size(199, 20);
			this->tbMerchantTab->TabIndex = 1;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(6, 48);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(57, 13);
			this->label27->TabIndex = 0;
			this->label27->Text = L"Tab Name";
			// 
			// btnMerchantSave
			// 
			this->btnMerchantSave->Enabled = false;
			this->btnMerchantSave->Location = System::Drawing::Point(168, 390);
			this->btnMerchantSave->Name = L"btnMerchantSave";
			this->btnMerchantSave->Size = System::Drawing::Size(75, 28);
			this->btnMerchantSave->TabIndex = 17;
			this->btnMerchantSave->Text = L"Save";
			this->btnMerchantSave->UseVisualStyleBackColor = true;
			// 
			// btnMerchantLoad
			// 
			this->btnMerchantLoad->Enabled = false;
			this->btnMerchantLoad->Location = System::Drawing::Point(7, 390);
			this->btnMerchantLoad->Name = L"btnMerchantLoad";
			this->btnMerchantLoad->Size = System::Drawing::Size(75, 28);
			this->btnMerchantLoad->TabIndex = 16;
			this->btnMerchantLoad->Text = L"Load";
			this->btnMerchantLoad->UseVisualStyleBackColor = true;
			this->btnMerchantLoad->Click += gcnew System::EventHandler(this, &MainForm::btnMerchantLoad_Click);
			// 
			// tpNpcSpawn
			// 
			this->tpNpcSpawn->Controls->Add(this->lbNpcSpawn);
			this->tpNpcSpawn->Controls->Add(this->btnNpcSpawnSave);
			this->tpNpcSpawn->Controls->Add(this->btnNpcSpawnLoad);
			this->tpNpcSpawn->Controls->Add(this->groupBox5);
			this->tpNpcSpawn->Location = System::Drawing::Point(4, 22);
			this->tpNpcSpawn->Name = L"tpNpcSpawn";
			this->tpNpcSpawn->Size = System::Drawing::Size(738, 455);
			this->tpNpcSpawn->TabIndex = 6;
			this->tpNpcSpawn->Text = L"NPC Spawns";
			this->tpNpcSpawn->UseVisualStyleBackColor = true;
			// 
			// lbNpcSpawn
			// 
			this->lbNpcSpawn->FormattingEnabled = true;
			this->lbNpcSpawn->Location = System::Drawing::Point(7, 3);
			this->lbNpcSpawn->Name = L"lbNpcSpawn";
			this->lbNpcSpawn->Size = System::Drawing::Size(236, 381);
			this->lbNpcSpawn->TabIndex = 24;
			this->lbNpcSpawn->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::lbNpcSpawn_SelectedIndexChanged);
			// 
			// btnNpcSpawnSave
			// 
			this->btnNpcSpawnSave->Enabled = false;
			this->btnNpcSpawnSave->Location = System::Drawing::Point(168, 390);
			this->btnNpcSpawnSave->Name = L"btnNpcSpawnSave";
			this->btnNpcSpawnSave->Size = System::Drawing::Size(75, 28);
			this->btnNpcSpawnSave->TabIndex = 26;
			this->btnNpcSpawnSave->Text = L"Save";
			this->btnNpcSpawnSave->UseVisualStyleBackColor = true;
			// 
			// btnNpcSpawnLoad
			// 
			this->btnNpcSpawnLoad->Enabled = false;
			this->btnNpcSpawnLoad->Location = System::Drawing::Point(7, 390);
			this->btnNpcSpawnLoad->Name = L"btnNpcSpawnLoad";
			this->btnNpcSpawnLoad->Size = System::Drawing::Size(75, 28);
			this->btnNpcSpawnLoad->TabIndex = 25;
			this->btnNpcSpawnLoad->Text = L"Load";
			this->btnNpcSpawnLoad->UseVisualStyleBackColor = true;
			this->btnNpcSpawnLoad->Click += gcnew System::EventHandler(this, &MainForm::btnNpcSpawnLoad_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tbNpcSpawnDirZ);
			this->groupBox5->Controls->Add(this->tbNpcSpawnLocZ);
			this->groupBox5->Controls->Add(this->tbNpcSpawnLocY);
			this->groupBox5->Controls->Add(this->tbNpcSpawnCooldown);
			this->groupBox5->Controls->Add(this->label17);
			this->groupBox5->Controls->Add(this->tbNpcSpawnDirX);
			this->groupBox5->Controls->Add(this->label18);
			this->groupBox5->Controls->Add(this->tbNpcSpawnLocX);
			this->groupBox5->Controls->Add(this->label19);
			this->groupBox5->Controls->Add(this->TbNpcSpawnNpcTblidx);
			this->groupBox5->Controls->Add(this->label20);
			this->groupBox5->Location = System::Drawing::Point(249, 3);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(482, 449);
			this->groupBox5->TabIndex = 23;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"NPC Spawn Data";
			// 
			// tbNpcSpawnDirZ
			// 
			this->tbNpcSpawnDirZ->Location = System::Drawing::Point(161, 68);
			this->tbNpcSpawnDirZ->Name = L"tbNpcSpawnDirZ";
			this->tbNpcSpawnDirZ->Size = System::Drawing::Size(62, 20);
			this->tbNpcSpawnDirZ->TabIndex = 12;
			// 
			// tbNpcSpawnLocZ
			// 
			this->tbNpcSpawnLocZ->Location = System::Drawing::Point(229, 43);
			this->tbNpcSpawnLocZ->Name = L"tbNpcSpawnLocZ";
			this->tbNpcSpawnLocZ->Size = System::Drawing::Size(62, 20);
			this->tbNpcSpawnLocZ->TabIndex = 11;
			// 
			// tbNpcSpawnLocY
			// 
			this->tbNpcSpawnLocY->Location = System::Drawing::Point(161, 43);
			this->tbNpcSpawnLocY->Name = L"tbNpcSpawnLocY";
			this->tbNpcSpawnLocY->Size = System::Drawing::Size(62, 20);
			this->tbNpcSpawnLocY->TabIndex = 10;
			// 
			// tbNpcSpawnCooldown
			// 
			this->tbNpcSpawnCooldown->Location = System::Drawing::Point(90, 94);
			this->tbNpcSpawnCooldown->Name = L"tbNpcSpawnCooldown";
			this->tbNpcSpawnCooldown->Size = System::Drawing::Size(133, 20);
			this->tbNpcSpawnCooldown->TabIndex = 9;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 97);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(78, 13);
			this->label17->TabIndex = 8;
			this->label17->Text = L"Respawn Time";
			// 
			// tbNpcSpawnDirX
			// 
			this->tbNpcSpawnDirX->Location = System::Drawing::Point(90, 69);
			this->tbNpcSpawnDirX->Name = L"tbNpcSpawnDirX";
			this->tbNpcSpawnDirX->Size = System::Drawing::Size(65, 20);
			this->tbNpcSpawnDirX->TabIndex = 7;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(7, 72);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(65, 13);
			this->label18->TabIndex = 6;
			this->label18->Text = L"vSpawn_Dir";
			// 
			// tbNpcSpawnLocX
			// 
			this->tbNpcSpawnLocX->Location = System::Drawing::Point(90, 43);
			this->tbNpcSpawnLocX->Name = L"tbNpcSpawnLocX";
			this->tbNpcSpawnLocX->Size = System::Drawing::Size(65, 20);
			this->tbNpcSpawnLocX->TabIndex = 5;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(7, 46);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(67, 13);
			this->label19->TabIndex = 4;
			this->label19->Text = L"vSpawn Loc";
			// 
			// TbNpcSpawnNpcTblidx
			// 
			this->TbNpcSpawnNpcTblidx->Location = System::Drawing::Point(90, 17);
			this->TbNpcSpawnNpcTblidx->Name = L"TbNpcSpawnNpcTblidx";
			this->TbNpcSpawnNpcTblidx->Size = System::Drawing::Size(133, 20);
			this->TbNpcSpawnNpcTblidx->TabIndex = 1;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(7, 20);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(70, 13);
			this->label20->TabIndex = 0;
			this->label20->Text = L"NPC TBLIDX";
			// 
			// tpMob
			// 
			this->tpMob->Controls->Add(this->lbMob);
			this->tpMob->Controls->Add(this->btnSaveMob);
			this->tpMob->Controls->Add(this->btnLoadMob);
			this->tpMob->Controls->Add(this->groupBox3);
			this->tpMob->Location = System::Drawing::Point(4, 22);
			this->tpMob->Name = L"tpMob";
			this->tpMob->Size = System::Drawing::Size(738, 455);
			this->tpMob->TabIndex = 4;
			this->tpMob->Text = L"Monster Table";
			this->tpMob->UseVisualStyleBackColor = true;
			// 
			// lbMob
			// 
			this->lbMob->FormattingEnabled = true;
			this->lbMob->Location = System::Drawing::Point(7, 3);
			this->lbMob->Name = L"lbMob";
			this->lbMob->Size = System::Drawing::Size(236, 381);
			this->lbMob->TabIndex = 16;
			this->lbMob->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::lbMob_SelectedIndexChanged);
			// 
			// btnSaveMob
			// 
			this->btnSaveMob->Enabled = false;
			this->btnSaveMob->Location = System::Drawing::Point(168, 390);
			this->btnSaveMob->Name = L"btnSaveMob";
			this->btnSaveMob->Size = System::Drawing::Size(75, 28);
			this->btnSaveMob->TabIndex = 18;
			this->btnSaveMob->Text = L"Save";
			this->btnSaveMob->UseVisualStyleBackColor = true;
			// 
			// btnLoadMob
			// 
			this->btnLoadMob->Enabled = false;
			this->btnLoadMob->Location = System::Drawing::Point(7, 390);
			this->btnLoadMob->Name = L"btnLoadMob";
			this->btnLoadMob->Size = System::Drawing::Size(75, 28);
			this->btnLoadMob->TabIndex = 17;
			this->btnLoadMob->Text = L"Load";
			this->btnLoadMob->UseVisualStyleBackColor = true;
			this->btnLoadMob->Click += gcnew System::EventHandler(this, &MainForm::btnLoadMob_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tbMobEp);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->tbMobLP);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->cbMobValid);
			this->groupBox3->Controls->Add(this->tbMobName);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Location = System::Drawing::Point(249, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(482, 449);
			this->groupBox3->TabIndex = 15;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Monster Data";
			// 
			// tbMobEp
			// 
			this->tbMobEp->Location = System::Drawing::Point(195, 43);
			this->tbMobEp->Name = L"tbMobEp";
			this->tbMobEp->Size = System::Drawing::Size(65, 20);
			this->tbMobEp->TabIndex = 7;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(139, 46);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(50, 13);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Basic EP";
			// 
			// tbMobLP
			// 
			this->tbMobLP->Location = System::Drawing::Point(62, 43);
			this->tbMobLP->Name = L"tbMobLP";
			this->tbMobLP->Size = System::Drawing::Size(65, 20);
			this->tbMobLP->TabIndex = 5;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(7, 46);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(49, 13);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Basic LP";
			// 
			// cbMobValid
			// 
			this->cbMobValid->AutoSize = true;
			this->cbMobValid->Location = System::Drawing::Point(362, 19);
			this->cbMobValid->Name = L"cbMobValid";
			this->cbMobValid->Size = System::Drawing::Size(83, 17);
			this->cbMobValid->TabIndex = 3;
			this->cbMobValid->Text = L"Validity Able";
			this->cbMobValid->UseVisualStyleBackColor = true;
			// 
			// tbMobName
			// 
			this->tbMobName->Location = System::Drawing::Point(48, 17);
			this->tbMobName->Name = L"tbMobName";
			this->tbMobName->Size = System::Drawing::Size(308, 20);
			this->tbMobName->TabIndex = 1;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(7, 20);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(35, 13);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Name";
			// 
			// tpMobSpawn
			// 
			this->tpMobSpawn->Controls->Add(this->lbMobSpawns);
			this->tpMobSpawn->Controls->Add(this->btnMobSpawnSave);
			this->tpMobSpawn->Controls->Add(this->btnMobSpawnLoad);
			this->tpMobSpawn->Controls->Add(this->groupBox4);
			this->tpMobSpawn->Location = System::Drawing::Point(4, 22);
			this->tpMobSpawn->Name = L"tpMobSpawn";
			this->tpMobSpawn->Padding = System::Windows::Forms::Padding(3);
			this->tpMobSpawn->Size = System::Drawing::Size(738, 455);
			this->tpMobSpawn->TabIndex = 5;
			this->tpMobSpawn->Text = L"Monster Spawns";
			this->tpMobSpawn->UseVisualStyleBackColor = true;
			// 
			// lbMobSpawns
			// 
			this->lbMobSpawns->FormattingEnabled = true;
			this->lbMobSpawns->Location = System::Drawing::Point(7, 3);
			this->lbMobSpawns->Name = L"lbMobSpawns";
			this->lbMobSpawns->Size = System::Drawing::Size(236, 381);
			this->lbMobSpawns->TabIndex = 20;
			this->lbMobSpawns->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::lbMobSpawns_SelectedIndexChanged);
			// 
			// btnMobSpawnSave
			// 
			this->btnMobSpawnSave->Enabled = false;
			this->btnMobSpawnSave->Location = System::Drawing::Point(168, 390);
			this->btnMobSpawnSave->Name = L"btnMobSpawnSave";
			this->btnMobSpawnSave->Size = System::Drawing::Size(75, 28);
			this->btnMobSpawnSave->TabIndex = 22;
			this->btnMobSpawnSave->Text = L"Save";
			this->btnMobSpawnSave->UseVisualStyleBackColor = true;
			// 
			// btnMobSpawnLoad
			// 
			this->btnMobSpawnLoad->Enabled = false;
			this->btnMobSpawnLoad->Location = System::Drawing::Point(7, 390);
			this->btnMobSpawnLoad->Name = L"btnMobSpawnLoad";
			this->btnMobSpawnLoad->Size = System::Drawing::Size(75, 28);
			this->btnMobSpawnLoad->TabIndex = 21;
			this->btnMobSpawnLoad->Text = L"Load";
			this->btnMobSpawnLoad->UseVisualStyleBackColor = true;
			this->btnMobSpawnLoad->Click += gcnew System::EventHandler(this, &MainForm::btnMobSpawnLoad_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tbMobSpawnDirZ);
			this->groupBox4->Controls->Add(this->tbMobSpawnLocZ);
			this->groupBox4->Controls->Add(this->tbMobSpawnLocY);
			this->groupBox4->Controls->Add(this->tbmobRespawn);
			this->groupBox4->Controls->Add(this->label16);
			this->groupBox4->Controls->Add(this->tbMobSpawnDirX);
			this->groupBox4->Controls->Add(this->label13);
			this->groupBox4->Controls->Add(this->tbMobSpawnLocX);
			this->groupBox4->Controls->Add(this->label14);
			this->groupBox4->Controls->Add(this->tbMobSpawnTblidx);
			this->groupBox4->Controls->Add(this->label15);
			this->groupBox4->Location = System::Drawing::Point(249, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(482, 449);
			this->groupBox4->TabIndex = 19;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Monster Spawn Data";
			// 
			// tbMobSpawnDirZ
			// 
			this->tbMobSpawnDirZ->Location = System::Drawing::Point(161, 68);
			this->tbMobSpawnDirZ->Name = L"tbMobSpawnDirZ";
			this->tbMobSpawnDirZ->Size = System::Drawing::Size(62, 20);
			this->tbMobSpawnDirZ->TabIndex = 12;
			// 
			// tbMobSpawnLocZ
			// 
			this->tbMobSpawnLocZ->Location = System::Drawing::Point(229, 43);
			this->tbMobSpawnLocZ->Name = L"tbMobSpawnLocZ";
			this->tbMobSpawnLocZ->Size = System::Drawing::Size(62, 20);
			this->tbMobSpawnLocZ->TabIndex = 11;
			// 
			// tbMobSpawnLocY
			// 
			this->tbMobSpawnLocY->Location = System::Drawing::Point(161, 43);
			this->tbMobSpawnLocY->Name = L"tbMobSpawnLocY";
			this->tbMobSpawnLocY->Size = System::Drawing::Size(62, 20);
			this->tbMobSpawnLocY->TabIndex = 10;
			// 
			// tbmobRespawn
			// 
			this->tbmobRespawn->Location = System::Drawing::Point(90, 94);
			this->tbmobRespawn->Name = L"tbmobRespawn";
			this->tbmobRespawn->Size = System::Drawing::Size(133, 20);
			this->tbmobRespawn->TabIndex = 9;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(6, 97);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(78, 13);
			this->label16->TabIndex = 8;
			this->label16->Text = L"Respawn Time";
			// 
			// tbMobSpawnDirX
			// 
			this->tbMobSpawnDirX->Location = System::Drawing::Point(90, 69);
			this->tbMobSpawnDirX->Name = L"tbMobSpawnDirX";
			this->tbMobSpawnDirX->Size = System::Drawing::Size(65, 20);
			this->tbMobSpawnDirX->TabIndex = 7;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(7, 72);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(65, 13);
			this->label13->TabIndex = 6;
			this->label13->Text = L"vSpawn_Dir";
			// 
			// tbMobSpawnLocX
			// 
			this->tbMobSpawnLocX->Location = System::Drawing::Point(90, 43);
			this->tbMobSpawnLocX->Name = L"tbMobSpawnLocX";
			this->tbMobSpawnLocX->Size = System::Drawing::Size(65, 20);
			this->tbMobSpawnLocX->TabIndex = 5;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(7, 46);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(67, 13);
			this->label14->TabIndex = 4;
			this->label14->Text = L"vSpawn Loc";
			// 
			// tbMobSpawnTblidx
			// 
			this->tbMobSpawnTblidx->Location = System::Drawing::Point(90, 17);
			this->tbMobSpawnTblidx->Name = L"tbMobSpawnTblidx";
			this->tbMobSpawnTblidx->Size = System::Drawing::Size(133, 20);
			this->tbMobSpawnTblidx->TabIndex = 1;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(7, 20);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(66, 13);
			this->label15->TabIndex = 0;
			this->label15->Text = L"MobTBLIDX";
			// 
			// tpSkills
			// 
			this->tpSkills->Controls->Add(this->lbSkills);
			this->tpSkills->Controls->Add(this->button1);
			this->tpSkills->Controls->Add(this->btnSkillLoad);
			this->tpSkills->Controls->Add(this->comboBox2);
			this->tpSkills->Controls->Add(this->comboBox3);
			this->tpSkills->Controls->Add(this->label57);
			this->tpSkills->Controls->Add(this->label58);
			this->tpSkills->Controls->Add(this->textBox20);
			this->tpSkills->Controls->Add(this->label59);
			this->tpSkills->Controls->Add(this->textBox21);
			this->tpSkills->Controls->Add(this->label60);
			this->tpSkills->Controls->Add(this->checkBox1);
			this->tpSkills->Controls->Add(this->tbSkillName);
			this->tpSkills->Controls->Add(this->label61);
			this->tpSkills->Location = System::Drawing::Point(4, 22);
			this->tpSkills->Name = L"tpSkills";
			this->tpSkills->Size = System::Drawing::Size(738, 455);
			this->tpSkills->TabIndex = 7;
			this->tpSkills->Text = L"Skill Table";
			this->tpSkills->UseVisualStyleBackColor = true;
			// 
			// tpProps
			// 
			this->tpProps->Controls->Add(this->propSaveBtn);
			this->tpProps->Controls->Add(this->propLoadBtn);
			this->tpProps->Controls->Add(this->lbProps);
			this->tpProps->Location = System::Drawing::Point(4, 22);
			this->tpProps->Name = L"tpProps";
			this->tpProps->Size = System::Drawing::Size(738, 455);
			this->tpProps->TabIndex = 9;
			this->tpProps->Text = L"Props";
			this->tpProps->UseVisualStyleBackColor = true;
			// 
			// propSaveBtn
			// 
			this->propSaveBtn->Enabled = false;
			this->propSaveBtn->Location = System::Drawing::Point(169, 389);
			this->propSaveBtn->Name = L"propSaveBtn";
			this->propSaveBtn->Size = System::Drawing::Size(75, 28);
			this->propSaveBtn->TabIndex = 10;
			this->propSaveBtn->Text = L"Save";
			this->propSaveBtn->UseVisualStyleBackColor = true;
			// 
			// propLoadBtn
			// 
			this->propLoadBtn->Enabled = false;
			this->propLoadBtn->Location = System::Drawing::Point(8, 389);
			this->propLoadBtn->Name = L"propLoadBtn";
			this->propLoadBtn->Size = System::Drawing::Size(75, 28);
			this->propLoadBtn->TabIndex = 9;
			this->propLoadBtn->Text = L"Load";
			this->propLoadBtn->UseVisualStyleBackColor = true;
			// 
			// lbProps
			// 
			this->lbProps->FormattingEnabled = true;
			this->lbProps->Location = System::Drawing::Point(8, 3);
			this->lbProps->Name = L"lbProps";
			this->lbProps->Size = System::Drawing::Size(236, 381);
			this->lbProps->TabIndex = 8;
			// 
			// log
			// 
			this->log->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->log->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->log->Location = System::Drawing::Point(0, 505);
			this->log->Name = L"log";
			this->log->ReadOnly = true;
			this->log->Size = System::Drawing::Size(746, 80);
			this->log->TabIndex = 4;
			this->log->Text = L"";
			// 
			// mainMenu
			// 
			this->mainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->mainMenu->Location = System::Drawing::Point(0, 0);
			this->mainMenu->Name = L"mainMenu";
			this->mainMenu->Size = System::Drawing::Size(746, 24);
			this->mainMenu->TabIndex = 1;
			this->mainMenu->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->loadGameDataToolStripMenuItem,
					this->loadPropertiesToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadGameDataToolStripMenuItem
			// 
			this->loadGameDataToolStripMenuItem->Name = L"loadGameDataToolStripMenuItem";
			this->loadGameDataToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->loadGameDataToolStripMenuItem->Text = L"Load Game Data";
			this->loadGameDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::loadGameDataToolStripMenuItem_Click);
			// 
			// loadPropertiesToolStripMenuItem
			// 
			this->loadPropertiesToolStripMenuItem->Name = L"loadPropertiesToolStripMenuItem";
			this->loadPropertiesToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->loadPropertiesToolStripMenuItem->Text = L"Load Properties";
			this->loadPropertiesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::LoadPropertiesToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(325, 91);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 24;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(325, 64);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 23;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(268, 94);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(51, 13);
			this->label57->TabIndex = 22;
			this->label57->Text = L"Job Type";
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(268, 67);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(56, 13);
			this->label58->TabIndex = 21;
			this->label58->Text = L"NPC Type";
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(456, 38);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(65, 20);
			this->textBox20->TabIndex = 20;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(400, 41);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(50, 13);
			this->label59->TabIndex = 19;
			this->label59->Text = L"Basic EP";
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(323, 38);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(65, 20);
			this->textBox21->TabIndex = 18;
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(268, 41);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(49, 13);
			this->label60->TabIndex = 17;
			this->label60->Text = L"Basic LP";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(623, 14);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(83, 17);
			this->checkBox1->TabIndex = 16;
			this->checkBox1->Text = L"Validity Able";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// tbSkillName
			// 
			this->tbSkillName->Location = System::Drawing::Point(309, 12);
			this->tbSkillName->Name = L"tbSkillName";
			this->tbSkillName->Size = System::Drawing::Size(308, 20);
			this->tbSkillName->TabIndex = 15;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(268, 15);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(35, 13);
			this->label61->TabIndex = 14;
			this->label61->Text = L"Name";
			// 
			// lbSkills
			// 
			this->lbSkills->FormattingEnabled = true;
			this->lbSkills->Location = System::Drawing::Point(8, 12);
			this->lbSkills->Name = L"lbSkills";
			this->lbSkills->Size = System::Drawing::Size(236, 381);
			this->lbSkills->TabIndex = 27;
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(169, 399);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 28);
			this->button1->TabIndex = 29;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// btnSkillLoad
			// 
			this->btnSkillLoad->Enabled = false;
			this->btnSkillLoad->Location = System::Drawing::Point(8, 399);
			this->btnSkillLoad->Name = L"btnSkillLoad";
			this->btnSkillLoad->Size = System::Drawing::Size(75, 28);
			this->btnSkillLoad->TabIndex = 28;
			this->btnSkillLoad->Text = L"Load";
			this->btnSkillLoad->UseVisualStyleBackColor = true;
			this->btnSkillLoad->Click += gcnew System::EventHandler(this, &MainForm::BtnSkillLoad_Click);
			// 
			// MainForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(746, 585);
			this->Controls->Add(this->mainTabs);
			this->Controls->Add(this->log);
			this->Controls->Add(this->mainMenu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"DBO Game Data Table Editor";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->mainTabs->ResumeLayout(false);
			this->worldTblTab->ResumeLayout(false);
			this->bodyPanel->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabTextAll->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tpItem->ResumeLayout(false);
			this->gbItem->ResumeLayout(false);
			this->gbItem->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbItemIcon))->EndInit();
			this->tpNpc->ResumeLayout(false);
			this->gbNpc->ResumeLayout(false);
			this->gbNpc->PerformLayout();
			this->tpMerchant->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->tpNpcSpawn->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->tpMob->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->tpMobSpawn->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->tpSkills->ResumeLayout(false);
			this->tpSkills->PerformLayout();
			this->tpProps->ResumeLayout(false);
			this->mainMenu->ResumeLayout(false);
			this->mainMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	container = new CTableContainer();
	flagManager.Create(CTableContainer::TABLE_COUNT);
	fileNameList.Create();
	
	/*Loadable Tables*/
	flagManager.Set(CTableContainer::TABLE_PC);
	flagManager.Set(CTableContainer::TABLE_NEWBIE);
	flagManager.Set(CTableContainer::TABLE_SKILL);
	flagManager.Set(CTableContainer::TABLE_NPC_SPAWN);
	flagManager.Set(CTableContainer::TABLE_MOB_SPAWN);

	/*Unmodified Tables that load properly*/
	flagManager.Set(CTableContainer::TABLE_BASIC_DROP);
	flagManager.Set(CTableContainer::TABLE_LEGENDARY_DROP);
	flagManager.Set(CTableContainer::TABLE_NORMAL_DROP);
	flagManager.Set(CTableContainer::TABLE_SUPERIOR_DROP);
	flagManager.Set(CTableContainer::TABLE_EACH_DROP);
	flagManager.Set(CTableContainer::TABLE_TYPE_DROP);
	flagManager.Set(CTableContainer::TABLE_EXCELLENT_DROP);
	flagManager.Set(CTableContainer::TABLE_QUEST_DROP);
	flagManager.Set(CTableContainer::TABLE_QUEST_PROBABILITY);

	flagManager.Set(CTableContainer::TABLE_DIRECTION_LINK);
	flagManager.Set(CTableContainer::TABLE_SCRIPT_LINK);

	/*Tables in Progress*/
	flagManager.Set(CTableContainer::TABLE_ITEM);
	flagManager.Set(CTableContainer::TABLE_DRAGONBALL_REWARD);
	flagManager.Set(CTableContainer::TABLE_EXP);
	flagManager.Set(CTableContainer::TABLE_PORTAL);
	flagManager.Set(CTableContainer::TABLE_USE_ITEM);
	flagManager.Set(CTableContainer::TABLE_WORLD);
	flagManager.Set(CTableContainer::TABLE_MOB);
	flagManager.Set(CTableContainer::TABLE_NPC);

	flagManager.Set(CTableContainer::TABLE_SYSTEM_EFFECT);
	flagManager.Set(CTableContainer::TABLE_TEXT_ALL);
	flagManager.Set(CTableContainer::TABLE_MERCHANT);
	
	/*Loadable Tables*/
	fileNameList.SetFileName(CTableContainer::TABLE_PC, "Table_PC_Data");
	fileNameList.SetFileName(CTableContainer::TABLE_NEWBIE, "Table_Newbie_Data");
	fileNameList.SetFileName(CTableContainer::TABLE_SKILL, "Table_Skill_Data");

	/*Unmodified Tables that load properly*/
	fileNameList.SetFileName(CTableContainer::TABLE_BASIC_DROP, "table_basic_drop_data");
	fileNameList.SetFileName(CTableContainer::TABLE_NORMAL_DROP, "table_normal_drop_data");
	fileNameList.SetFileName(CTableContainer::TABLE_SUPERIOR_DROP, "table_superior_drop_data");
	fileNameList.SetFileName(CTableContainer::TABLE_EXCELLENT_DROP, "table_excellent_drop_data");
	fileNameList.SetFileName(CTableContainer::TABLE_LEGENDARY_DROP, "table_legendary_drop_data");
	fileNameList.SetFileName(CTableContainer::TABLE_QUEST_DROP, "table_quest_drop_data");
	fileNameList.SetFileName(CTableContainer::TABLE_TYPE_DROP, "table_type_drop_data");
	fileNameList.SetFileName(CTableContainer::TABLE_EACH_DROP, "table_each_drop_data");
	fileNameList.SetFileName(CTableContainer::TABLE_QUEST_PROBABILITY, "Table_Quest_Probablity_data");
	fileNameList.SetFileName(CTableContainer::TABLE_SCRIPT_LINK, "Table_Script_Link_Data");
	fileNameList.SetFileName(CTableContainer::TABLE_DIRECTION_LINK, "Table_Direction_Link_Data");

	/*Tables in progress
	* If tables are here they load but don't have correct structures.
	* Just a correct size.
	*/
	fileNameList.SetFileName(CTableContainer::TABLE_ITEM, "Table_Item_Data");
	fileNameList.SetFileName(CTableContainer::TABLE_DRAGONBALL_REWARD, "Table_DB_Reward_Data");
	fileNameList.SetFileName(CTableContainer::TABLE_EXP, "table_exp_data");
	fileNameList.SetFileName(CTableContainer::TABLE_PORTAL, "Table_Portal_Data");
	fileNameList.SetFileName(CTableContainer::TABLE_USE_ITEM, "Table_Use_Item_Data");
	fileNameList.SetFileName(CTableContainer::TABLE_WORLD, "Table_World_Data");

	fileNameList.SetFileName(CTableContainer::TABLE_MOB, "Table_MOB_Data");
	fileNameList.SetFileName(CTableContainer::TABLE_NPC, "Table_NPC_Data");


	fileNameList.SetFileName(CTableContainer::TABLE_SYSTEM_EFFECT, "table_system_effect_data");
	fileNameList.SetFileName(CTableContainer::TABLE_TEXT_ALL, "table_text_all_data");
	fileNameList.SetFileName(CTableContainer::TABLE_MERCHANT, "table_merchant_data");

	this->log->AppendText("---------------------------------------------------------\nTo start go File > Load Game Data\n---------------------------------------------------------\n\n");
}
private: System::Void loadGameDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->log->AppendText("Loading game data ...\n");
	if (container->Create(flagManager, ".\\Data", &fileNameList, CTable::LOADING_METHOD_BINARY, GetACP(), NULL)) //Loading Method Binary
	{
		this->worldTblLoad->Enabled = true;
		this->btnItemLoad->Enabled = true;
		//this->worldTblSave->Enabled = true;
		this->btnTextAllTblLoad->Enabled = true;
		this->btnLoadMob->Enabled = true;
		this->btnNpcLoad->Enabled = true;
		this->btnMobSpawnLoad->Enabled = true;
		this->btnNpcSpawnLoad->Enabled = true;
		this->btnMerchantLoad->Enabled = true;
		this->btnSkillLoad->Enabled = true;




		populateComboBoxes();


		this->log->AppendText("Game Data Loaded!\n");
	}
	else
		this->log->AppendText("Failed to load Game Data!\n");
}
private: System::Void worldTblLoad_Click(System::Object^  sender, System::EventArgs^  e) {
	List<ListData^>^ data = gcnew List<ListData^>();
	
	for (CTable::TABLEIT iter = container->GetWorldTable()->Begin(); container->GetWorldTable()->End() != iter; iter++)
	{
		sWORLD_TBLDAT* pWorldTableData = (sWORLD_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", gcnew String(pWorldTableData->szName), pWorldTableData->tblidx);
		it->Value = pWorldTableData->tblidx;

		data->Add(it);
	}

	this->worldTblList->DisplayMember = "Text";
	this->worldTblList->ValueMember = "Value";
	this->worldTblList->DataSource = data;
}
private: System::Void worldTblList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	int value = ((ListData^)this->worldTblList->SelectedItem)->Value;

	sWORLD_TBLDAT data = *(sWORLD_TBLDAT*)container->GetWorldTable()->FindData(value);

	this->fldWorldTblName->Text = gcnew String(data.szName);
	this->cbWorldTblDynamic->Checked = data.bDynamic;
	this->fldWorldTblCreateCount->Text = String::Format("{0}", data.nCreateCount);
	this->fldWorldTblDoorType->Text = String::Format("{0}", data.byDoorType);
	this->fldWorldTblMobSp->Text = gcnew String(data.wszMobSpawn_Table_Name);
	this->fldWorldTblNpcSp->Text = gcnew String(data.wszNpcSpawn_Table_Name);
	this->fldWorldTblObjSp->Text = gcnew String(data.wszObjSpawn_Table_Name);
	this->fldVStart1LocX->Text = String::Format("{0}", data.vStart1Loc.x);
	this->fldVStart1LocY->Text = String::Format("{0}", data.vStart1Loc.y);
	this->fldVStart1LocZ->Text = String::Format("{0}", data.vStart1Loc.z);
	this->tbSplitSize->Text = String::Format("{0}", data.fSplitSize);
	data.bDynamic;
	data.bNight_Able;
	data.vBattleEndLoc;
	data.vBattleStartLoc;
}
private: System::Void worldTblSave_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void btnTextAllTblLoad_Click(System::Object^  sender, System::EventArgs^  e) {
	List<ListData^>^ data = gcnew List<ListData^>();

	CTextTable* pTextTbl = container->GetTextAllTable()->GetActionTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "Action", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetChatCommandTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "ChatCommand", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetCSTextTble();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "CSText", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetDBRewardTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "DBReward", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetDragonTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "Dragon", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetETCTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "ETC", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetFilteringTable();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "Filtering", pData->tblidx);
		it->Value = pData->tblidx;
		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetGMToolTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "GMTool", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetHelpPopoTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "HelpPopo", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetHelpTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "Help", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetHTBSetTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "HTBSet", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetItemTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "NormalItem", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetMapNameTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "MapName", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetMerchantTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "Merchant", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetMilePostTable();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "MilePost", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetMobTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "Mob", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetNpcDialogTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "NpcDialog", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetNPCTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "NPC", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetObjectTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "Object", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetQuestItemTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "QuestItem", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetSkillTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "Skill", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetSystemEffectTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "SystemEffect", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetTMQTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "TMQ", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetUseItemTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "UseItem", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}
	pTextTbl = container->GetTextAllTable()->GetDBOTipTbl();
	for (CTable::TABLEIT iter = pTextTbl->Begin(); pTextTbl->End() != iter; iter++)
	{
		sTEXT_TBLDAT* pData = (sTEXT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();

		it->Text = String::Format("{0} [{1}]", "DBOTip", pData->tblidx);
		it->Value = pData->tblidx;

		data->Add(it);
	}

	this->textAllTblList->DisplayMember = "Text";
	this->textAllTblList->ValueMember = "Value";
	this->textAllTblList->DataSource = data;
}
private: System::Void textAllTblList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	int value = ((ListData^)this->textAllTblList->SelectedItem)->Value;
	String^ text = ((ListData^)this->textAllTblList->SelectedItem)->Text;

	CTextTable* pTextTbl= NULL;

	if (Regex::IsMatch(text, "Action"))
		pTextTbl = container->GetTextAllTable()->GetActionTbl();
	if (Regex::IsMatch(text, "ChatCommand"))
		pTextTbl = container->GetTextAllTable()->GetChatCommandTbl();
	if (Regex::IsMatch(text, "CSText"))
		pTextTbl = container->GetTextAllTable()->GetCSTextTble();
	if (Regex::IsMatch(text, "DBReward"))
		pTextTbl = container->GetTextAllTable()->GetDBRewardTbl();
	if (Regex::IsMatch(text, "Dragon"))
		pTextTbl = container->GetTextAllTable()->GetDragonTbl();
	if (Regex::IsMatch(text, "ETC"))
		pTextTbl = container->GetTextAllTable()->GetETCTbl();
	if (Regex::IsMatch(text, "Filtering"))
		pTextTbl = container->GetTextAllTable()->GetFilteringTable();
	if (Regex::IsMatch(text, "GMTool"))
		pTextTbl = container->GetTextAllTable()->GetGMToolTbl();
	if (Regex::IsMatch(text, "HelpPopo"))
		pTextTbl = container->GetTextAllTable()->GetHelpPopoTbl();
	if (Regex::IsMatch(text, "Help "))
		pTextTbl = container->GetTextAllTable()->GetHelpTbl();
	if (Regex::IsMatch(text, "HTBSet"))
		pTextTbl = container->GetTextAllTable()->GetHTBSetTbl();
	if (Regex::IsMatch(text, "NormalItem"))
		pTextTbl = container->GetTextAllTable()->GetItemTbl();
	if (Regex::IsMatch(text, "MapName"))
		pTextTbl = container->GetTextAllTable()->GetMapNameTbl();
	if (Regex::IsMatch(text, "Merchant"))
		pTextTbl = container->GetTextAllTable()->GetMerchantTbl();
	if (Regex::IsMatch(text, "MilePost"))
		pTextTbl = container->GetTextAllTable()->GetMilePostTable();
	if (Regex::IsMatch(text, "Mob"))
		pTextTbl = container->GetTextAllTable()->GetMobTbl();
	if (Regex::IsMatch(text, "NpcDialog"))
		pTextTbl = container->GetTextAllTable()->GetNpcDialogTbl();
	if (Regex::IsMatch(text, "NPC "))
		pTextTbl = container->GetTextAllTable()->GetNPCTbl();
	if (Regex::IsMatch(text, "Object"))
		pTextTbl = container->GetTextAllTable()->GetObjectTbl();
	if (Regex::IsMatch(text, "QuestItem"))
		pTextTbl = container->GetTextAllTable()->GetQuestItemTbl();
	if (Regex::IsMatch(text, "Skill"))
		pTextTbl = container->GetTextAllTable()->GetSkillTbl();
	if (Regex::IsMatch(text, "SystemEffect"))
		pTextTbl = container->GetTextAllTable()->GetSystemEffectTbl();
	if (Regex::IsMatch(text, "TMQ"))
		pTextTbl = container->GetTextAllTable()->GetTMQTbl();
	if (Regex::IsMatch(text, "UseItem"))
		pTextTbl = container->GetTextAllTable()->GetUseItemTbl();
	if (Regex::IsMatch(text, "DBOTip"))
		pTextTbl = container->GetTextAllTable()->GetDBOTipTbl();

	sTEXT_TBLDAT data = *(sTEXT_TBLDAT*)pTextTbl->FindData(value);
	this->strTextAllTbl->Clear();
	this->strTextAllTbl->AppendText(gcnew String(data.wstrText.c_str()));
}
private: System::Void btnItemLoad_Click(System::Object^  sender, System::EventArgs^  e) {
	List<ListData^>^ data = gcnew List<ListData^>();

	CItemTable* pItemTable = container->GetItemTable();
	CTextTable* pTextTable = container->GetTextAllTable()->GetItemTbl();
	int i = 0;
	for (CTable::TABLEIT iter = pItemTable->Begin(); pItemTable->End() != iter; iter++)
	{
		if (i < 6)
		{
			continue;
		}
		else
		{
			sITEM_TBLDAT* pItemTblDat = (sITEM_TBLDAT*)(iter->second);
			ListData^ it = gcnew ListData();
			std::wstring ws = pTextTable->GetText(pItemTblDat->Name);
			std::string s(ws.begin(), ws.end());
			it->Text = String::Format(L"{0} [{1}]", gcnew String(s.c_str()), pItemTblDat->tblidx);
			it->Value = pItemTblDat->tblidx;


			data->Add(it);
		}
	}
	
	
	this->lbItems->DisplayMember = "Text";
	this->lbItems->ValueMember = "Value";
	this->lbItems->DataSource = data;

	this->btnItemAddNew->Enabled = true;

}

private: System::Void lbItems_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	unsigned int value = ((ListData^)this->lbItems->SelectedItem)->Value;
	CItemTable* pItemTable = container->GetItemTable();
	CTextTable* pTextTable = container->GetTextAllTable()->GetItemTbl();

	try {

	sITEM_TBLDAT data = *(sITEM_TBLDAT*)pItemTable->FindData(value);
	std::wstring ws = pTextTable->GetText(data.Name);
	std::string s(ws.begin(), ws.end());

		this->tbItemName->Text = gcnew String(s.c_str());
		if (data.bValidity_Able > 0)
			this->cbValidity->Checked = 1;
		else
		this->cbValidity->Checked = data.bValidity_Able;

		this->tbItemCost->Text = String::Format("{0}", data.dwCost);
		this->tbItemSell->Text = String::Format("{0}", data.bySell_Price);
		this->tbItemLevel->Text = String::Format("{0}", data.byNeed_Level);
		if(data.byEquip_Type != 255)
			this->cbItemEquipType->SelectedIndex = data.byEquip_Type;
		else
			this->cbItemEquipType->SelectedIndex = 9;

		if(data.byItem_Type == 255)
			this->cbItemType->SelectedIndex = 52;
		else
			this->cbItemType->SelectedIndex = data.byItem_Type;


		//this->tbItemClass->Text = String::Format("{0}", data.dwNeed_Class_Bit_Flag);
		String^ Name = gcnew String(data.szIcon_Name);
		int index = cbItemIcons->FindString(Name->ToLower());
		cbItemIcons->SelectedIndex = index;

	}
	catch (Object^ exc)
	{
		throw gcnew System::Exception("something bad happened");
	}
}

private: System::Void cbItemIcons_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	if (pbItemIcon->Image != nullptr) {
		delete pbItemIcon->Image;
		pbItemIcon->Image = nullptr;
	}
	String^ imagePath = "./texture/gui/icon/" + cbItemIcons->GetItemText(cbItemIcons->SelectedItem);
	pbItemIcon->Image = Image::FromFile(imagePath);
}



private: System::Void btnLoadMob_Click(System::Object^  sender, System::EventArgs^  e) {
	List<ListData^>^ data = gcnew List<ListData^>();

	CMobTable* pMobTable = container->GetMobTable();
	CTextTable* pTextTable = container->GetTextAllTable()->GetMobTbl();
	for (CTable::TABLEIT iter = pMobTable->Begin(); pMobTable->End() != iter; iter++)
	{
		sMOB_TBLDAT* pMobTblDat = (sMOB_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();
		std::wstring ws = pTextTable->GetText(pMobTblDat->Name);
		std::string s(ws.begin(), ws.end());
		it->Text = String::Format(L"{0} [{1}]", gcnew String(s.c_str()), pMobTblDat->tblidx);
		it->Value = pMobTblDat->tblidx;

		data->Add(it);
	}


	this->lbMob->DisplayMember = "Text";
	this->lbMob->ValueMember = "Value";
	this->lbMob->DataSource = data;

}




private: System::Void lbMob_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	unsigned int value = ((ListData^)this->lbMob->SelectedItem)->Value;
	CMobTable* pMobTable = container->GetMobTable();
	CTextTable* pTextTable = container->GetTextAllTable()->GetMobTbl();
	try {

		sMOB_TBLDAT data = *(sMOB_TBLDAT*)pMobTable->FindData(value);
		std::wstring ws = pTextTable->GetText(data.Name);
		std::string s(ws.begin(), ws.end());

		this->tbMobName->Text = gcnew String(s.c_str());
		if (data.bValidity_Able > 0)
			this->cbValidity->Checked = 1;
		else
			this->cbValidity->Checked = data.bValidity_Able;
		this->tbMobLP->Text = String::Format("{0}", data.wBasic_LP);
		this->tbMobEp->Text = String::Format("{0}", data.wBasic_EP);

	}
	catch (Object^ exc)
	{
		throw gcnew System::Exception("something bad happened");
	}

}
private: System::Void btnMobSpawnLoad_Click(System::Object^  sender, System::EventArgs^  e) {
	List<ListData^>^ data = gcnew List<ListData^>();

	CSpawnTable* pMobSpawnTable = container->GetMobSpawnTable(1);
	CTextTable* pTextTable = container->GetTextAllTable()->GetMobTbl();
	CMobTable* pMobTable = container->GetMobTable();

	for (CTable::TABLEIT iter = pMobSpawnTable->Begin(); pMobSpawnTable->End() != iter; iter++)
	{
		sSPAWN_TBLDAT* pMobSpawnTblDat = (sSPAWN_TBLDAT*)(iter->second);

		ListData^ it = gcnew ListData();
		it->Text = String::Format(L"[{0}]",  pMobSpawnTblDat->tblidx);
		it->Value = pMobSpawnTblDat->tblidx;
		data->Add(it);
	}

	this->lbMobSpawns->DisplayMember = "Text";
	this->lbMobSpawns->ValueMember = "Value";
	this->lbMobSpawns->DataSource = data;
}


private: System::Void lbMobSpawns_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	unsigned int value = ((ListData^)this->lbMobSpawns->SelectedItem)->Value;
	CSpawnTable* pMobTable = container->GetMobSpawnTable(1);
	try {

		sSPAWN_TBLDAT* data = (sSPAWN_TBLDAT*)pMobTable->FindData(value);
		if (data != NULL)
		{
			this->tbMobSpawnLocX->Text = String::Format("{0}", data->vSpawn_Loc.x);
			this->tbMobSpawnLocY->Text = String::Format("{0}",  data->vSpawn_Loc.y);
			this->tbMobSpawnLocZ->Text = String::Format("{0}", data->vSpawn_Loc.z);
			this->tbMobSpawnDirX->Text = String::Format("{0}", data->vSpawn_Dir.x);
			this->tbMobSpawnDirZ->Text = String::Format("{0}", data->vSpawn_Dir.z);
			this->tbMobSpawnTblidx->Text = String::Format("{0}", data->mob_Tblidx);
			this->tbmobRespawn->Text = String::Format("{0}", data->wSpawn_Cool_Time);
		}
	}
	catch (Object^ exc)
	{
		throw gcnew System::Exception("something bad happened");
	}
}
private: System::Void btnNpcSpawnLoad_Click(System::Object^  sender, System::EventArgs^  e) {

	List<ListData^>^ data = gcnew List<ListData^>();

	CSpawnTable* pNpcSpawnTable = container->GetNpcSpawnTable(1);
	CTextTable* pTextTable = container->GetTextAllTable()->GetMobTbl();

	for (CTable::TABLEIT iter = pNpcSpawnTable->Begin(); pNpcSpawnTable->End() != iter; iter++)
	{
		sSPAWN_TBLDAT* pNpcSpawnTblDat = (sSPAWN_TBLDAT*)(iter->second);

		ListData^ it = gcnew ListData();
		it->Text = String::Format(L"[{0}]", pNpcSpawnTblDat->tblidx);
		it->Value = pNpcSpawnTblDat->tblidx;
		data->Add(it);
	}

	this->lbNpcSpawn->DisplayMember = "Text";
	this->lbNpcSpawn->ValueMember = "Value";
	this->lbNpcSpawn->DataSource = data;
}
private: System::Void lbNpcSpawn_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	unsigned int value = ((ListData^)this->lbNpcSpawn->SelectedItem)->Value;
	CSpawnTable* pMobTable = container->GetNpcSpawnTable(1);
	try {

		sSPAWN_TBLDAT* data = (sSPAWN_TBLDAT*)pMobTable->FindData(value);
		if (data != NULL)
		{
			this->tbNpcSpawnLocX->Text = String::Format("{0}", data->vSpawn_Loc.x);
			this->tbNpcSpawnLocY->Text = String::Format("{0}", data->vSpawn_Loc.y);
			this->tbNpcSpawnLocZ->Text = String::Format("{0}", data->vSpawn_Loc.z);
			this->tbNpcSpawnDirX->Text = String::Format("{0}", data->vSpawn_Dir.x);
			this->tbNpcSpawnDirZ->Text = String::Format("{0}", data->vSpawn_Dir.z);
			this->TbNpcSpawnNpcTblidx->Text = String::Format("{0}", data->mob_Tblidx);
			this->tbNpcSpawnCooldown->Text = String::Format("{0}", data->wSpawn_Cool_Time);
		}
	}
	catch (Object^ exc)
	{
		throw gcnew System::Exception("something bad happened");
	}
}
private: System::Void btnNpcLoad_Click(System::Object^  sender, System::EventArgs^  e) {

	List<ListData^>^ data = gcnew List<ListData^>();

	CNPCTable* pMobTable = container->GetNpcTable();
	CTextTable* pTextTable = container->GetTextAllTable()->GetNPCTbl();
	for (CTable::TABLEIT iter = pMobTable->Begin(); pMobTable->End() != iter; iter++)
	{
		sNPC_TBLDAT* pMobTblDat = (sNPC_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();
		std::wstring ws = pTextTable->GetText(pMobTblDat->Name);
		std::string s(ws.begin(), ws.end());
		it->Text = String::Format(L"{0} [{1}]", gcnew String(s.c_str()), pMobTblDat->tblidx);
		it->Value = pMobTblDat->tblidx;

		data->Add(it);
	}


	this->lbNpc->DisplayMember = "Text";
	this->lbNpc->ValueMember = "Value";
	this->lbNpc->DataSource = data;

}



private: System::Void lbNpc_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	unsigned int value = ((ListData^)this->lbNpc->SelectedItem)->Value;
	CNPCTable* pMobTable = container->GetNpcTable();
	CTextTable* pTextTable = container->GetTextAllTable()->GetNPCTbl();
	try {

		sNPC_TBLDAT data = *(sNPC_TBLDAT *)pMobTable->FindData(value);
		std::wstring ws = pTextTable->GetText(data.Name);
		std::string s(ws.begin(), ws.end());

		this->tbNpcName->Text = gcnew String(s.c_str());
		if (data.bValidity_Able > 1)
			this->cbNpcValid->Checked = 1;
		else
			this->cbNpcValid->Checked = data.bValidity_Able;
		this->tbNpcLP->Text = String::Format("{0}", data.wBasic_LP);
		this->tbNpcEP->Text = String::Format("{0}", data.wBasic_EP);
		this->cbNPCJob->SelectedIndex = data.byJob;
		this->cbNpcType->SelectedIndex = data.byNpcType;
		

	}
	catch (Object^ exc)
	{
		throw gcnew System::Exception("something bad happened");
	}
}

private: System::Char* GetJobTypeText(byte byJob)
{
	switch (byJob)
	{
		case NPC_JOB_WEAPON_MERCHANT:
			return L"Weapon Merchant";
		case NPC_JOB_ARMOR_MERCHANT:
			return L"Armor Merchant";
		case NPC_JOB_GOODS_MERCHANT:
			return L"Goods Merchant";
		case NPC_JOB_SCOUTER_MERCHANT:
			return L"Scouter Merchant";
		case NPC_JOB_GUARD:
			return L"Guard";
		case NPC_JOB_SKILL_TRAINER_HFI:
			return L"HFI Trainer";
		case NPC_JOB_SKILL_TRAINER_HMY:
			return L"HMY Trainer";
		case NPC_JOB_SKILL_TRAINER_HEN:
			return L"HEN Trainer";
		case NPC_JOB_SKILL_TRAINER_NFI:
			return L"NFI Trainer";
		case NPC_JOB_SKILL_TRAINER_NMY:
			return L"NMY Trainer";
		case NPC_JOB_SKILL_TRAINER_MMI:
			return L"MMI Trainer";
		case NPC_JOB_SKILL_TRAINER_MWO:
			return L"MWO Trainer";
		case NPC_JOB_BANKER:
			return L"Banker";
		case NPC_JOB_TALKER:
			return L"Talker";
		case NPC_JOB_GUILD_MANAGER:
			return L"Guild Manager";
		case NPC_JOB_SUMMON_PET:
			return L"Summon Pet";
		case NPC_JOB_DOGI_MERCHANT:
			return L"Dogi Merchant";
		case NPC_JOB_SPECIAL_WEAPON_MERCHANT:
			return L"Special Weapon Merchant";
		case NPC_JOB_SPECIAL_ARMOR_MERCHANT:
			return L"Special Armor Merchant";
		case NPC_JOB_SPECIAL_GOODS_MERCHANT:
			return L"Special Goods Merchant";
		case NPC_JOB_SPECIAL_FOODS_MERCHANT:
			return L"Special Food Merchant";
		case NPC_JOB_SPECIAL_SCOUTER_MERCHANT:
			return L"Special Scouter Merchant";
		case NPC_JOB_GRAND_SKILL_TRAINER_HFI:
			return L"HFI Master";
		case NPC_JOB_GRAND_SKILL_TRAINER_HMY:
			return L"HMY Master";
		case NPC_JOB_GRAND_SKILL_TRAINER_HEN:
			return L"HEN Master";
		case NPC_JOB_GRAND_SKILL_TRAINER_NFI:
			return L"NFI Master";
		case NPC_JOB_GRAND_SKILL_TRAINER_NMY:
			return L"NMY Master";
		case NPC_JOB_GRAND_SKILL_TRAINER_MMI:
			return L"MMI Master";
		case NPC_JOB_GRAND_SKILL_TRAINER_MWO:
			return L"MWO Master";
		case NPC_JOB_SUB_WEAPON_MERCHANT:
			return L"Sub Weapon Mechant";
		case NPC_JOB_GATE_KEEPER:
			return L"Gate Keeper";
		case NPC_JOB_VENDING_MACHINE:
			return L"Vending Machine";
		case NPC_JOB_TIMEMACHINE_MERCHANT:
			return L"TMQ Merchant";
		case NPC_JOB_PORTAL_MAN:
			return L"Portal Manager";
		default:
			return L"unknown";
	}
}


private: System::Char* GetMobType(byte byType)
{
	switch (byType)
	{
	case MOB_TYPE_ANIMAL:
		return L"Animal";
	case MOB_TYPE_HUMAN_ANIMAL:
		return L"Human Animal";
	case MOB_TYPE_DINOSAUR:
		return L"Dinosaur";
	case MOB_TYPE_ALIEN:
		return L"Alien";
	case MOB_TYPE_ANDROID:
		return L"Android";
	case MOB_TYPE_ROBOT:
		return L"Robot";
	case MOB_TYPE_DRAGON:
		return L"Dragon";
	case MOB_TYPE_DEVIL:
		return L"Devil";
	case MOB_TYPE_UNDEAD:
		return L"Undead";
	case MOB_TYPE_PLANT:
		return L"Plant";
	case MOB_TYPE_INSECT:
		return L"Insect";
	case MOB_TYPE_HUMAN:
		return L"Human";
	case MOB_TYPE_NAMEC:
		return L"Namekian";
	case MOB_TYPE_MAJIN:
		return L"Majin";
	case MOB_TYPE_BUILDING:
	return L"Building";
	default:
		return L"unknown";
	}
}
private: System::Char* GetMerchantType(byte byMerchantType)
{
	switch (byMerchantType)
	{

		case MERCHANT_SELL_TYPE_ITEM:
			return L"Item";
		case MERCHANT_SELL_TYPE_SKILL:
			return L"Skill";
		case MERCHANT_SELL_TYPE_HTB_SKILL:
			return L"HTB Skill";
		case MERCHANT_SELL_TYPE_BANK:
			return L"Bank";
		case MERCHANT_SELL_TYPE_TIMEMACHINE:
			return L"TMQ";
		case MERCHANT_SELL_TYPE_BUDOKAI:
			return L"Budokai";
		case MERCHANT_SELL_TYPE_GAMBLE:
			return L"Gamble";
		case MERCHANT_SELL_TYPE_NETPY:
			return L"NetPy";
		default:
			return L"unknown";
	}
}
private: System::Void btnMerchantLoad_Click(System::Object^  sender, System::EventArgs^  e) {
	List<ListData^>^ data = gcnew List<ListData^>();

	CMerchantTable* pMobTable = container->GetMerchantTable();
	CTextTable* pTextTable = container->GetTextAllTable()->GetMerchantTbl();
	for (CTable::TABLEIT iter = pMobTable->Begin(); pMobTable->End() != iter; iter++)
	{
		sMERCHANT_TBLDAT* pMobTblDat = (sMERCHANT_TBLDAT*)(iter->second);
		ListData^ it = gcnew ListData();
		std::wstring ws = pTextTable->GetText(pMobTblDat->Tab_Name);
		std::string s(ws.begin(), ws.end());
		it->Text = String::Format(L"{0} [{1}]", gcnew String(s.c_str()), pMobTblDat->tblidx);
		it->Value = pMobTblDat->tblidx;

		data->Add(it);
	}


	this->lbMerchant->DisplayMember = "Text";
	this->lbMerchant->ValueMember = "Value";
	this->lbMerchant->DataSource = data;
}

private: System::Void lbMerchant_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	unsigned int value = ((ListData^)this->lbMerchant->SelectedItem)->Value;
	CMerchantTable* pMobTable = container->GetMerchantTable();
	CTextTable* pTextTable = container->GetTextAllTable()->GetMerchantTbl();
	CItemTable* pItemTable = container->GetItemTable();
	try {
		this->lbMerchantItems->Items->Clear();
		sMERCHANT_TBLDAT data = *(sMERCHANT_TBLDAT *)pMobTable->FindData(value);
		std::wstring ws = pTextTable->GetText(data.Tab_Name);
		std::string s(ws.begin(), ws.end());
		this->tbMerchantTab->Text = gcnew String(s.c_str());
		
		this->tbMerchantSell->Text = gcnew String(GetMerchantType(data.bySell_Type));;
		for (int j = 0; j < NTL_MAX_MERCHANT_COUNT; j++)
		{
			if (data.aitem_Tblidx[j] != INVALID_TBLIDX)
			{
				sITEM_TBLDAT* item = (sITEM_TBLDAT*)pItemTable->FindData(data.aitem_Tblidx[j]);
				this->lbMerchantItems->Items->Add(String::Format("{0}/{1}", data.aitem_Tblidx[j], item->dwCost));
			}		 

		}
		

	}
	catch (Object^ exc)
	{
		throw gcnew System::Exception("something bad happened");
	}
}
public: System::Char* GetItemType(byte byItemType)
{
	switch (byItemType)
	{
		case ITEM_TYPE_GLOVE:
		  return L"Gloves";
		case ITEM_TYPE_STAFF:
			return L"Staff";
		case ITEM_TYPE_GUN:
			return L"Gun";
		case ITEM_TYPE_DUAL_GUN:
			return L"Dual Gun";
		case ITEM_TYPE_CLAW:
			return L"Claw";
		case ITEM_TYPE_AXE:
			return L"Axe";
		case ITEM_TYPE_SCROLL:
			return L"Scroll";
		case ITEM_TYPE_GEM:
			return L"Gem";
		case ITEM_TYPE_STICK:
			return L"Stick";
		case ITEM_TYPE_SWORD:
			return L"Sword";
		case ITEM_TYPE_FAN:
			return L"Fan";
		case ITEM_TYPE_WAND:
			return L"Wand";
		case ITEM_TYPE_BAZOOKA:
			return L"Bazooka";
		case ITEM_TYPE_BACK_PACK:
			return L"Back Pack";
		case ITEM_TYPE_INSTRUMENT:
			return L"Instrument";
		case ITEM_TYPE_CLUB:
			return L"Club";
		case ITEM_TYPE_DRUM:
			return L"Drum";
		case ITEM_TYPE_MASK:
			return L"Mask";

		case ITEM_TYPE_JACKET:
			return L"Jacket";
		case ITEM_TYPE_PANTS:
			return L"Pants";
		case ITEM_TYPE_BOOTS:
			return L"Boots";

		case ITEM_TYPE_NECKLACE:
			return L"Necklace";
		case ITEM_TYPE_EARRING:
			return L"Earring";
		case ITEM_TYPE_RING:
			return L"Ring";

		case ITEM_TYPE_SCOUTER:
			return L"Scouter";
		case ITEM_TYPE_SCOUTER_PART:
		return L"Scouter Part";
    
	/*	case ITEM_TYPE_COSTUME:
			return L"Costume";*/
		case ITEM_TYPE_BAG:
			return L"Bag";
		case ITEM_TYPE_QUEST:
			return L"Quest";
		case ITEM_TYPE_STONE:
			return L"Stone";

		case ITEM_TYPE_RECOVER:
			return L"Recover";
		case ITEM_TYPE_FOOD:
			return L"Food";
		case ITEM_TYPE_UTILITY:
			return L"Utility";
		case ITEM_TYPE_CHARM:
			return L"Charm";
		case ITEM_TYPE_CAPSULE:
			return L"Capsule";
		case ITEM_TYPE_FUEL:
			return L"Fuel";
		case ITEM_TYPE_JUNK:
			return L"Junk";
		case ITEM_TYPE_COLLECTION:
			return L"Collection";
		case ITEM_TYPE_WAREHOUSE:
			return L"Warehouse";
		case ITEM_TYPE_DRAGONBALL:
			return L"DragonBall";
		case ITEM_TYPE_GAMBLE:
			return L"Gamble";
		case ITEM_TYPE_MATERIAL:
			return L"Material";
		case ITEM_TYPE_RECIPE:
			return L"Recipe";
		case ITEM_TYPE_HOIPOIROCK:
			return L"HoiPoiRock";
		case ITEM_TYPE_DOGI:
			return L"Dogi";
		case ITEM_TYPE_PURE_STONE:
			return L"Pure Stone";
		case ITEM_TYPE_BLACK_STONE:
			return L"Black Stone";
		case ITEM_TYPE_NETPYSTORE:
			return L"NetpyStore";
		//case ITEM_TYPE_HAIR:
		//	return L"Hair";
		//case ITEM_TYPE_ACCESSORY1:
		//	return L"Accessory1";
		//case ITEM_TYPE_ACCESSORY2:
		//	return L"Accessory2";
		//case ITEM_TYPE_ACCESSORY3:
		//	return L"Accessory3";
		default:
			return L"Unknown";
	}
}
public: System::Char* GetEquipType(byte byEquipType)
{
	switch (byEquipType)
	{

	case EQUIP_TYPE_MAIN_WEAPON:
		return L"Main Weapon";
	case EQUIP_TYPE_SUB_WEAPON:
		return L"Sub Weapon";
	case EQUIP_TYPE_ARMOR:
		return L"Armor";
	case EQUIP_TYPE_SCOUTER:
		return L"Scouter";
	case EQUIP_TYPE_QUEST:
		return L"Quest";
	case EQUIP_TYPE_ACCESSORY:
		return L"Accessory";
	/*case EQUIP_TYPE_DOGI:
		return L"Dogi";
	case EQUIP_TYPE_HAIR:
		return L"Hair";
	case EQUIP_TYPE_COSTUME_ACC:
		return L"Costume Accessory";*/
	default:
		return L"unknown";
	}
}

private: System::Void pbItemIcon_Click(System::Object^  sender, System::EventArgs^  e) {
}


private: System::Void populateComboBoxes() {

	System::String ^path = "texture/gui/icon";
	cli::array<System::String ^>^ a = System::IO::Directory::GetFiles(path);
	for each(System::String ^ file in a)
		cbItemIcons->Items->Add(System::IO::Path::GetFileName(file));


	List<ListData^>^ jobs = gcnew List<ListData^>();
	for (int i = NPC_JOB_FIRST; i != NPC_JOB_LAST; i++)
	{
		ListData^ jobIt = gcnew ListData();
		jobIt->Text = gcnew String(GetJobTypeText(i));
		jobIt->Value = i;

		jobs->Add(jobIt);
	}
	this->cbNPCJob->DisplayMember = "Text";
	this->cbNPCJob->ValueMember = "Value";
	this->cbNPCJob->DataSource = jobs;


	List<ListData^>^ mobType = gcnew List<ListData^>();
	for (int i = MOB_TYPE_FIRST; i != 14; i++)
	{
		ListData^ mobTypeIt = gcnew ListData();
		mobTypeIt->Text = gcnew String(GetMobType(i));
		mobTypeIt->Value = i;

		mobType->Add(mobTypeIt);
	}
	this->cbNpcType->DisplayMember = "Text";
	this->cbNpcType->ValueMember = "Value";
	this->cbNpcType->DataSource = mobType;

	List<ListData^>^ equipType = gcnew List<ListData^>();
	for (int i = EQUIP_TYPE_FIRST; i <= EQUIP_TYPE_COUNT; i++)
	{
		ListData^ equipTypeIt = gcnew ListData();
		equipTypeIt->Text = gcnew String(GetEquipType(i));
		if (i == 9)
			equipTypeIt->Value = 255;
		else
			equipTypeIt->Value = i;
		equipType->Add(equipTypeIt);
	}

	this->cbItemEquipType->DisplayMember = "Text";
	this->cbItemEquipType->ValueMember = "Value";
	this->cbItemEquipType->DataSource = equipType;

	List<ListData^>^ itemType = gcnew List<ListData^>();
	for (int i = ITEM_TYPE_FIRST; i <= ITEM_TYPE_COUNT; i++)
	{
		ListData^ itemTypeIt = gcnew ListData();
		itemTypeIt->Text = gcnew String(GetItemType(i));
		if (i == 52)
			itemTypeIt->Value = 255;
		else
			itemTypeIt->Value = i;
		itemType->Add(itemTypeIt);
	}

	this->cbItemType->DisplayMember = "Text";
	this->cbItemType->ValueMember = "Value";
	this->cbItemType->DataSource = itemType;
}
private: System::Void btnItemAddNew_Click(System::Object^  sender, System::EventArgs^  e) {

	unsigned int value = ((ListData^)this->lbItems->SelectedItem)->Value;
	if (value == -1)
		MessageBox::Show("No Item Selected for Base Data");
	else
	{
		CItemTable* pItemTable = container->GetItemTable();
		sITEM_TBLDAT* data = (sITEM_TBLDAT*)pItemTable->FindData(value);
		AddEntry^ InsertForm = gcnew AddEntry(data);
		InsertForm->Show();
	}
}
private: System::Void LoadPropertiesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void BtnSkillLoad_Click(System::Object^ sender, System::EventArgs^ e) 
{
	List<ListData^>^ data = gcnew List<ListData^>();

	CSkillTable* pItemTable = container->GetSkillTable();
	CTextTable* pTextTable = container->GetTextAllTable()->GetSkillTbl();
	int i = 0;
	for (CTable::TABLEIT iter = pItemTable->Begin(); pItemTable->End() != iter; iter++)
	{
		if (i < 6)
		{
			continue;
		}
		else
		{
			sITEM_TBLDAT* pItemTblDat = (sITEM_TBLDAT*)(iter->second);
			ListData^ it = gcnew ListData();
			std::wstring ws = pTextTable->GetText(pItemTblDat->Name);
			std::string s(ws.begin(), ws.end());
			it->Text = String::Format(L"{0} [{1}]", gcnew String(s.c_str()), pItemTblDat->tblidx);
			it->Value = pItemTblDat->tblidx;


			data->Add(it);
		}
	}


	this->lbSkills->DisplayMember = "Text";
	this->lbSkills->ValueMember = "Value";
	this->lbSkills->DataSource = data;


	}
};

}
