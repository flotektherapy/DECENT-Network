// decent_wallet_ui_gui_contentdetails
/*
 *	File: decent_wallet_ui_gui_contentdetails.cpp
 *
 *	Created on: 21 Feb 2017
 *	Created by: Davit Kalantaryan (Email: davit.kalantaryan@desy.de)
 *
 *  This file implements ...
 *
 */


#include "decent_wallet_ui_gui_contentdetails.hpp"

static const char* s_vcpcFieldsGeneral[NUMBER_OF_SUB_LAYOUTS] = {
    "Author", "Expiration","Created","Price", "Amount","Asset ID",
    "Averege Rating","Size","Times Bought"
};


static const char* s_vcpcFieldsBougth[NUMBER_OF_SUB_LAYOUTS] = {
    "Author", "Expiration","Created","Price", "Amount","Asset ID",
    "Averege Rating","Size","Times Bought"
};

typedef const char* TypeCpcChar;
typedef TypeCpcChar* NewType;

static NewType  s_vFields[]={s_vcpcFieldsGeneral,s_vcpcFieldsBougth};

decent::wallet::ui::gui::ContentDetails::ContentDetails()
{
    int i, nIndexKent(1), nIndexZuyg(0);

    for(i=0;i<NUMBER_OF_SUB_LAYOUTS;++i,nIndexZuyg+=2,nIndexKent+=2)
    {
        m_vLabels[nIndexZuyg].setStyleSheet("font-weight: bold");
        m_vSub_layouts[i].addWidget(&m_vLabels[nIndexZuyg]);
        m_vSub_layouts[i].addWidget(&m_vLabels[nIndexKent]);
        m_main_layout.addLayout(&m_vSub_layouts[i]);
    }
    setLayout(&m_main_layout);
}

decent::wallet::ui::gui::ContentDetails::~ContentDetails()
{
    //
}


void decent::wallet::ui::gui::ContentDetails::execCD(const decent::wallet::ui::gui::SDigitalContent& a_cnt_details)
{
#if 1
    int i,nIndexZuyg(0);
    NewType vNames = s_vFields[a_cnt_details.type];
    m_pContentInfo = &a_cnt_details;

    for(i=0;i<NUMBER_OF_SUB_LAYOUTS;++i,nIndexZuyg+=2)
    {
        m_vLabels[nIndexZuyg].setText(tr(vNames[i]));
    }

    m_vLabels[1].setText(tr(m_pContentInfo->author.c_str()));
    m_vLabels[3].setText(tr(m_pContentInfo->expiration.c_str()));
    m_vLabels[5].setText(tr(m_pContentInfo->created.c_str()));
    m_vLabels[7].setText(QString::number(m_pContentInfo->price.amount,'f').remove( QRegExp("0+$") ).remove( QRegExp("\\.$") ));
    m_vLabels[9].setText(tr("???"));
    m_vLabels[11].setText(tr("???"));
    m_vLabels[13].setText(QString::number(m_pContentInfo->AVG_rating,'f').remove( QRegExp("0+$") ).remove( QRegExp("\\.$") ));
    //QString::number(aTemporar.AVG_rating,'f').remove( QRegExp("0+$") ).remove( QRegExp("\\.$") )
    QString qsSizeTxt = QString::number(m_pContentInfo->size,'f').remove( QRegExp("0+$") ).remove( QRegExp("\\.$") ) +
            tr(" MB");
    m_vLabels[15].setText(qsSizeTxt);
    m_vLabels[17].setText(tr("???"));

    QDialog::exec();
#endif
}
